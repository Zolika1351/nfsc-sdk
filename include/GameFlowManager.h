class GameFlowManager
{
public:
	void* pSingleFunction;						// 00-04
	uint32_t SingleFunctionParam;				// 04-08
	char* pSingleFunctionName;					// 08-0C
	void* pLoopingFunction;						// 0C-10
	char* pLoopingFunctionName;					// 10-14
	bool WaitingForCallback;					// 14-15
	uint8_t pad[3];								// 15-18
	char* pCallbackName;						// 18-1C
	uint32_t CallbackPhase;						// 1C-20
	uint32_t CurrentGameFlowState;				// 20-24
};
VALIDATE_OFFSET(GameFlowManager, CurrentGameFlowState, 0x20);

auto& TheGameFlowManager = *(GameFlowManager*)0xA99B9C;