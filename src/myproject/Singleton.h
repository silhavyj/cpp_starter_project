#pragma once

#include <mutex>
#include <memory>

template<class T>
class Singleton
{
public:
    static T* GetInstance()
    {
        std::call_once(m_initFlag, [=]() {
            Singleton<T>::m_instance = std::make_unique<T>();
        });
        
        return m_instance.get();
    }

private:
    static std::unique_ptr<T> m_instance;
    static std::once_flag m_initFlag;
};

template<class T>
std::unique_ptr<T> Singleton<T>::m_instance = nullptr;

template<class T>
std::once_flag Singleton<T>::m_initFlag = {};