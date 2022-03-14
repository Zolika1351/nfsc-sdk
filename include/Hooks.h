namespace plugin
{
	namespace processSimSystemEvent
	{
		uintptr_t returnAddress;
		std::list<void(*)()> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f();
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				pushad
				call Run
				popad
				jmp returnAddress
			}
		}
		// after SimTask::Run, runs in-game when not paused
		void Add(void(*funcPtr)())
		{
			funcPtrs.emplace_back(funcPtr);
		}
	};
	
	namespace processWorldEvent
	{
		uintptr_t returnAddress;
		std::list<void(*)()> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f();
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				pushad
				call Run
				popad
				jmp returnAddress
			}
		}
		// after World_Service, always runs except while loading
		void Add(void(*funcPtr)())
		{
			funcPtrs.emplace_back(funcPtr);
		}
	};

	namespace drawingEvent
	{
		uintptr_t callAddress;
		std::list<void(*)()> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f();
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				push ebx
				call callAddress
				pop ebx
				pushad
				call Run
				popad
				ret
			}
		}
		// right before a frame is displayed, do anything d3d related here
		void Add(void(*funcPtr)())
		{
			funcPtrs.emplace_back(funcPtr);
		}
	}
}