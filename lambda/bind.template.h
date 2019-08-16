// https://www.jianshu.com/p/d22904f30930
#include <iostream>

//通过递归方式实现的一个简易的makeindex，
template<std::size_t ...>
struct IndexTuple{};

template<std::size_t N, std::size_t... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...>{};

//递归继承结束条件, 同时也是对上面模板的一个偏特化
template<std::size_t... indexes>
struct MakeIndexes<0, indexes...> {
    typedef IndexTuple<indexes...> type;
};

//--------------------------------------------------------------

template <typename Fn, typename ...Params>
class _BindImpl_ {
public:
    typedef typename MakeIndexes<sizeof...(Params)>::type __my_indices;

    Fn _fn;
    std::tuple<Params...> _params;

    _BindImpl_(Fn&& fn, Params&&... params) : _fn(std::forward<Fn>(fn)), _params(std::forward<Params>(params)...)
    {

    }

    void operator()()
    {
        return invoke(__my_indices());
    }

    template <std::size_t ..._Indx>
    void invoke(IndexTuple<_Indx...>)
    {
        _fn(std::get<_Indx>(_params)...);
    }
};

template<typename Fn, typename ...Params>
_BindImpl_<Fn, Params...> _bind(Fn &&fn, Params &&... params)
{
    return _BindImpl_<Fn, Params...>(std::forward<Fn>(fn), std::forward<Params>(params)...);
}

