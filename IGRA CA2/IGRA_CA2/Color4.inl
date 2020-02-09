/* Color4.inl
 * ----------
 * Inline file to separate function template implementation from the header
 * file Color4.h
 * ----------
 * Done by Brandon Gui (1828865) from DIT/FT/2B/05
 */

template<typename T>
inline Color4<T>::Color4() : red{0}, green{0}, blue{0}, alpha{0}
{}

template<typename T>
inline Color4<T>::Color4(T red, T green, T blue, T alpha) : red{red}, green{green}, blue{blue}, alpha{alpha}
{}