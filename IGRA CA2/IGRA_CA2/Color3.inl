template<typename T>
inline Color3<T>::Color3() : red{0}, green{0}, blue{0}
{}

template<typename T>
inline Color3<T>::Color3(T red, T green, T blue) : red{red}, green{green}, blue{blue}
{}

template<typename T>
inline Color3<T>::operator Color4<T>() const
{
    return Color4<T>{red, green, blue, 0};
}