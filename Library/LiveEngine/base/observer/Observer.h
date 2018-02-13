//
//  Observer.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/10.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Observer__
#define __LiveEngine__Observer__

namespace live
{
    namespace observer
    {
        struct Action {
            uint32_t actionId = 0;
        };

        template <typename T> class Observer;

        template <typename T> class Subject
        {
          public:
            Subject() : observers(new Observers()) {}

            virtual ~Subject() { observers.reset(); }

            /**
             * Observer で監視設定を行う.
             *
             * @parma observer [in] Observer.
             */
            void attach(const std::shared_ptr<Observer<T>>& observer)
            {
                observers->add(observer);
            }

            /**
             * Observer の観察を解除する.
             *
             * @param observer [in] 登録する Observer.
             */
            void detach(const std::shared_ptr<Observer<T>>& observer)
            {
                observers->remove(observer);
            }

          protected:
            void notifyAll(const Action& action)
            {
                observers->prune();
                observers->notify(*static_cast<T*>(this), action);
            };

          private:
            class Observers;
            std::unique_ptr<Observers> observers;
        };

        template<typename T>
        class Subject<T>::Observers
        {
        public:
            ~Observers() { m_observers.clear(); }
            
            void notify(const T& sender, const Action& action);
            void add(const std::shared_ptr<Observer<T>>& observer);
            void remove(const std::shared_ptr<Observer<T>>& observer);
            void prune();
            
        private:
            bool exists(const std::shared_ptr<Observer<T>>& observer);
            void remove(const std::vector<std::weak_ptr<Observer<T>>>& v);
            std::vector<std::weak_ptr<Observer<T>>> m_observers;
        };
        
        template <typename T> class Observer
        {
          public:
            virtual ~Observer() {}

            /**
             *  Subjectからの通知を受け取る処理
             *
             *  @param sender 通知の送信元
             *  @param action 変更の情報
             */
            virtual void notify(const T& sender, const Action& action) = 0;
        };

        #include "Observers.inl"
    }
}

#endif /* defined(__LiveEngine__Observer__) */
