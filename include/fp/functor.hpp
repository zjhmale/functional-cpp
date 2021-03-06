#pragma once

#include <functional>
using namespace std;

namespace fp {
  template <template <typename...> class F>
  struct Functor {
    template <typename A, typename B>
    static function <F<B>(F<A>)> fmap(function <B(A)>);
    template <typename A, typename B, typename C>
    static function <F<A, C>(F<A, B>)> fmap2(function <C(B)>);
  };

  template <template <typename...> class F, typename A, typename B>
  static function <F<B>(F<A>)> fmap(function <B(A)> f) {
    return Functor<F>::fmap(f);
  }

  template <template <typename...> class F, typename A, typename B>
  static F<B> fmap_(function <B(A)> f, F<A> v) {
    return Functor<F>::fmap(f)(v);
  }

  template <template <typename...> class F, typename A, typename B>
  static F<B> operator %(function <B(A)> f, F<A> v) {
    return Functor<F>::fmap(f)(v);
  }

  template <template <typename...> class F, typename A, typename B>
  static F<B> operator ^(F<A> v, function <B(A)> f) {
    return Functor<F>::fmap(f)(v);
  }

  template <template <typename...> class F, typename A, typename B, typename C>
  static function <F<A, C>(F<A, B>)> fmap2(function <C(B)> f) {
    return Functor<F>::fmap2(f);
  }

  template <template <typename...> class F, typename A, typename B, typename C>
  static F<A, C> fmap_2(function <C(B)> f, F<A, B> v) {
    return Functor<F>::fmap2(f)(v);
  }

  template <template <typename...> class F, typename A, typename B, typename C>
  static F<A, C> operator &&(function <C(B)> f, F<A, B> v) {
    return Functor<F>::fmap2(f)(v);
  }

  template <template <typename...> class F, typename A, typename B, typename C>
  static F<A, C> operator ||(F<A, B> v, function <C(B)> f) {
    return Functor<F>::fmap2(f)(v);
  }

}
