/* GameObject.inl
 * --------------
 * Contains template implementations of the template functions.
 * --------------
 * Done by Brandon Gui (1828865) from DIT/FT/2B/05.
 */

// Adds the component of type T to this GameObject. T must be a type derived from the Component class.
template<typename T>
inline T& GameObject::AddComponent()
{
	T* instance{new T{*this}};

	if (Program::program->GetCurrentPhase() == Program::Phase::Initializing)
	{
		components.push_back(instance);
	}
	else
	{
		newlyAddedComponents.push_back(instance);
	}

	return *instance;
}

// Gets the first occurence of a component that inherits from type T from this GameObject.
// A null pointer is returned if no such component is found.
template<typename T>
inline T* GameObject::GetComponent()
{
	// search in the standard components vector first
	for (Component *&component : components)
	{
		// attempt to downcast from Component to type T (casting to a more specific type)
		// if the downcast is successful, we will get the component as type T
		// if the downcast fails, we will get a null pointer to type T
		T* instance{dynamic_cast<T*>(component)};

		if (instance != nullptr)
		{
			// we already found the component, so return it
			return instance;
		}
	}

	// then search in the components that are about to be Start-ed
	for (Component *&component : componentsToStart)
	{
		// attempt to downcast from Component to type T (casting to a more specific type)
		// if the downcast is successful, we will get the component as type T
		// if the downcast fails, we will get a null pointer to type T
		T* instance{dynamic_cast<T*>(component)};

		if (instance != nullptr)
		{
			// we already found the component, so return it
			return instance;
		}
	}

	// and finally, the newly-added components
	for (Component *&component : newlyAddedComponents)
	{
		// attempt to downcast from Component to type T (casting to a more specific type)
		// if the downcast is successful, we will get the component as type T
		// if the downcast fails, we will get a null pointer to type T
		T* instance{dynamic_cast<T*>(component)};

		if (instance != nullptr)
		{
			// we already found the component, so return it
			return instance;
		}
	}

	// if we managed to reach here, it means we've found nothing
	// so we return a null pointer
	return nullptr;
}
