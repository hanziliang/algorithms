// https://www.jianshu.com/p/d22904f30930
#include <iostream>

template<typename ...T>
class ___tuple{public:___tuple(){ printf("this will never be call\n");} };

template<typename HEAD, typename ...tlist>
class ___tuple<HEAD, tlist...> : public ___tuple<tlist...>
{
public:
    ___tuple(HEAD head, tlist... args) : ___tuple<tlist...>(args...), value(head) {
//        std::cout << "i=" << i++ << ", head=" << head << std::endl;
    }

    HEAD value;
};

template<>
class ___tuple<> {
    public:
    ___tuple() {
        std::cout << "class ___tuple<> is call" << std::endl;
    }
};

template<int N, typename ...T>
struct __tuple_at;

template<int N, typename T, typename ...TLIST>
struct __tuple_at<N, ___tuple<T, TLIST...> >
{
    static_assert(sizeof...(TLIST) >= N, "wrong index");
    typedef typename __tuple_at<N - 1, ___tuple<TLIST...> >::value_type value_type;
    typedef typename __tuple_at<N - 1, ___tuple<TLIST...> >::tuple_type tuple_type;
};

template<typename T, typename ...TLIST>
struct __tuple_at<0, ___tuple<T, TLIST...> > {
    public:
    typedef T value_type;
    typedef ___tuple<T, TLIST...> tuple_type;
};

template<int N, typename HEAD, typename ...TLIST>
typename __tuple_at<N, ___tuple<HEAD, TLIST...> >::value_type
__get_tuple_at(___tuple<HEAD, TLIST...> _tuple)
{
    typedef typename __tuple_at<N, ___tuple<HEAD, TLIST...> >::value_type VALUE;
    typedef typename __tuple_at<N, ___tuple<HEAD, TLIST...> >::tuple_type TUPLE;
    VALUE ret = ((TUPLE) _tuple).value;
    return ret;
}

#define print_line() {printf("---------------------------\n"); }
