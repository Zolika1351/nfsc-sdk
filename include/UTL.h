namespace UTL
{
	namespace COM
	{
		class Object
		{
		public:
			class _IList
			{
			public:
				uint8_t pad[0x4];

				template<typename T>
				T* Find()
				{
					return ((T*(__thiscall*)(_IList*, uint32_t))(0x60CB50))(this, T::IHandle());
				}
			};

			uint32_t vft;											// 00-04
			_IList* _mInterfaces;									// 04-08

			template<typename T>
			T* Find()
			{
				return _mInterfaces->Find<T>();
			}
		};
		VALIDATE_SIZE(Object, 0x8);
	}
}