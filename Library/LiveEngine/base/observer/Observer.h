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
        class Subject;
        
        class Observer
        {
        public:
            friend class Subject;
            Observer() : subject(nullptr) {}
            
            void observe(std::unique_ptr<Subject> sub)
            {
                subject = std::move(sub);
            }
            virtual void notify() = 0;
        protected:
            std::unique_ptr<Subject> subject;
        };
        
        class Subject
        {
        public:
            void notifyAll()
            {
                std::for_each(observers.begin(), observers.end(), [](std::unique_ptr<Observer>& observer){
                    observer->notify();
                });
            }
        private:
            std::vector<std::unique_ptr<Observer>> observers;
        };
    }
}

#endif /* defined(__LiveEngine__Observer__) */
