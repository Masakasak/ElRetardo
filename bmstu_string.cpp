#include <iostream>

namespace bmstu {
    template <typename T>
    class string {
    public:
        string() : ptr_(nullptr), size_(0) {}

        string(const char *c_str) : size_(strlen_(c_str)) {
            ptr_ = new T[size_ + 1];
            for (int i = 0; i < size_; i++) {
                ptr_[i] = c_str[i];
            }
            ptr_[size_] = '\0';
        }

        string(const string &other) : size_(other.size_) {
            ptr_ = new T[size_ + 1];
            for (int i = 0; i < size_; i++) {
                ptr_[i] = other.ptr_[i];
            }
            ptr_[size_] = '\0';
        }

        string(string &&dying) : ptr_(dying.ptr_), size_(dying.size_) {
            dying.ptr_ = nullptr;
        }

        ~string() {
            delete[] ptr_;
        }

        const T *c_str() const {
            return ptr_;
        }

        size_t size() const {
            return size_;
        }

        string &operator=(const string &other) {
            if (this != &other) {
                delete[] ptr_;
                size_ = other.size_;
                ptr_ = new T[size_ + 1];
                for (int i = 0; i < size_; i++) {
                    ptr_[i] = other.ptr_[i];
                }
                ptr_[size_] = '\0';
            }
            return *this;
        }

        string &operator=(string &&other) {
            if (this != &other) {
                delete[] ptr_;
                ptr_ = other.ptr_;
                size_ = other.size_;
                other.ptr_ = nullptr;
            }
            return *this;
        }

        string &operator=(const char *c_str) {
            delete[] ptr_;
            size_ = strlen_(c_str);
            ptr_ = new T[size_ + 1];
            for (int i = 0; i < size_; i++) {
                ptr_[i] = c_str[i];
            }
            ptr_[size_] = '\0';
            return *this;
        }


        friend string operator+(const string &left, const string &right) {
            string result;
            result.size_ = left.size_ + right.size_;
            result.ptr_ = new T[result.size_ + 1];
            int index = 0;
            for (int i = 0; i < left.size_; i++) {
                result.ptr_[index++] = left.ptr_[i];
            }
            for (int i = 0; i < right.size_; i++) {
                result.ptr_[index++] = right.ptr_[i];
            }
            result.ptr_[result.size_] = '\0';
            return result;
        }

        friend std::ostream &operator<<(std::ostream &os, const string &obj) {
            os << obj.ptr_;
            return os;
        }

        friend std::istream &operator>>(std::istream &is, string &obj) {
            std::string temp;
            is >> temp;
            obj = temp.c_str();
            return is;
        }

        string &operator+=(const string &other) {
            T *temp = new T[size_ + other.size_ + 1];
            int index = 0;
            for (int i = 0; i < size_; i++) {
                temp[index++] = ptr_[i];
            }
            for (int i = 0; i < other.size_; i++) {
                temp[index++] = other.ptr_[i];
            }
            temp[size_ + other.size_] = '\0';

            delete[] ptr_;
            ptr_ = temp;
            size_ += other.size_;

            return *this;
        }

        string &operator+=(T symbol) {
            T *temp = new T[size_ + 2];
            int index = 0;
            for (int i = 0; i < size_; i++) {
                temp[index++] = ptr_[i];
            }
            temp[index++] = symbol;
            temp[index] = '\0';

            delete[] ptr_;
            ptr_ = temp;
            size_++;

            return *this;
        }

        T &operator[](size_t index) {
            return ptr_[index];
        }

    private:
        static size_t strlen_(const T *str) {
            size_t len = 0;
            while (str[len] != '\0') {
                len++;
            }
            return len;
        }

        void clean_() {
            delete[] ptr_;
            ptr_ = nullptr;
            size_ = 0;
        }

        T *ptr_;
        size_t size_;
    };
}

int main() {
    bmstu::string<char> str1("Bmstu");
    bmstu::string<char> str2("Top");
    bmstu::string<char> str3 = str1 + str2;

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl; 
    std::cout << str3 << std::endl; 

    str1 += str2;
    std::cout << str1 << std::endl; 

    str1[0] = 'b';
    std::cout << str1 << std::endl; 

    return 0;
}