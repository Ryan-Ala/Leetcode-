class Foo {
public:
    pthread_mutex_t mtx1,mtx2;
    Foo() {
        pthread_mutex_init(&mtx1,nullptr);
        pthread_mutex_init(&mtx2,nullptr);
        pthread_mutex_lock(&mtx1);
        pthread_mutex_lock(&mtx2);
    }
    ~Foo() {
        pthread_mutex_destroy(&mtx1);
        pthread_mutex_destroy(&mtx2);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_mutex_unlock(&mtx1);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mtx1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_mutex_unlock(&mtx1);
        pthread_mutex_unlock(&mtx2);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mtx2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&mtx2);
    }
};