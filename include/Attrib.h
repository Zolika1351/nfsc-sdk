class Attrib
{
public:
	class Collection
	{
	public:
		uint8_t pad[0x4];						// 00-04
	};

	class Instance
	{
	public:
		uint32_t pad;					// 00-04
		void* m_pData;					// 04-08
		uint8_t pad2[8];				// 08-10

		Instance() {};
		Instance(Collection* collection, int unk)
		{
			((Instance*(__thiscall*)(Instance*, Collection*, int))0x461340)(this, collection, unk);
		}
		~Instance()
		{
			((void(__thiscall*)(Instance*))0x469870)(this);
		}

		void* GetAttributePointer(uint32_t hash, int unk)
		{
			return ((void*(__thiscall*)(Instance*, uint32_t, int))0x463A80)(this, hash, unk);
		}
	};
	VALIDATE_SIZE(Instance, 0x10);

	class Class
	{
	public:
		uint32_t GetFirstCollection()
		{
			return ((uint32_t(__thiscall*)(Class*))0x4652E0)(this);
		}
		uint32_t GetNextCollection(uint32_t current)
		{
			return ((uint32_t(__thiscall*)(Class*, uint32_t))0x465300)(this, current);
		}
	};

	class Database
	{
	public:
		static inline Database*& sThis = *(Database**)0xA8499C;

		Class* GetClass(uint32_t hash)
		{
			return ((Class*(__thiscall*)(Database*, uint32_t))0x4655E0)(this, hash);
		}
	};

	static Collection* FindCollection(uint32_t type, uint32_t collection)
	{
		return ((Collection*(__cdecl*)(uint32_t, uint32_t))0x465930)(type, collection);
	}
};