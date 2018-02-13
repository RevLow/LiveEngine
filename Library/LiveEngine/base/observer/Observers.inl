template <typename T>
void Subject<T>::Observers::notify(const T& sender, const Action& action)
{
    std::for_each(m_observers.begin(), m_observers.end(),
                  [this, &sender, &action](const std::weak_ptr<Observer<T>>& p) {
                      if (auto sp = p.lock())
                      {
                          sp->notify(sender, action);
                      }
                  });
}

template <typename T>
void Subject<T>::Observers::add(const std::shared_ptr<Observer<T>>& observer)
{
    if (this->exists(observer))
    {
        return;
    }

    m_observers.emplace_back(observer);
}

template <typename T>
void Subject<T>::Observers::remove(const std::shared_ptr<Observer<T>>& observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
                           [observer](std::weak_ptr<Observer<T>>& p) {
                               return p.lock() == observer;
                           });

    if (it == m_observers.end())
    {
        return;
    }

    m_observers.erase(it);
}

template <typename T>
void Subject<T>::Observers::prune()
{
    std::vector<std::weak_ptr<Observer<T>>> invalids;

    std::for_each(m_observers.begin(), m_observers.end(),
                  [this, &invalids](const std::weak_ptr<Observer<T>>& p) {
                      if (p.lock())
                      {
                          return;
                      }

                      invalids.emplace_back(p);
                  });

    this->remove(invalids);
}

template <typename T>
bool Subject<T>::Observers::exists(const std::shared_ptr<Observer<T>>& observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
                           [observer](std::weak_ptr<Observer<T>>& p) {
                               return p.lock() == observer;
                           });

    return it != m_observers.end();
}

template <typename T>
void Subject<T>::Observers::remove(
    const std::vector<std::weak_ptr<Observer<T>>>& v)
{
    std::for_each(
        v.begin(), v.end(), [this](const std::weak_ptr<Observer<T>>& p) {
            auto it = std::remove_if(m_observers.begin(), m_observers.end(),
                                     [p](const std::weak_ptr<Observer<T>>& pp) {
                                         return &p == &pp;
                                     });

            m_observers.erase(it, m_observers.end());
        });
}
