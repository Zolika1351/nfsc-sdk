enum GameFlowState
{
	GAMEFLOW_STATE_NONE,
	GAMEFLOW_STATE_LOADING_FRONTEND,
	GAMEFLOW_STATE_UNLOADING_FRONTEND,
	GAMEFLOW_STATE_IN_FRONTEND,
	GAMEFLOW_STATE_LOADING_REGION,
	GAMEFLOW_STATE_LOADING_TRACK,
	GAMEFLOW_STATE_RACING,
	GAMEFLOW_STATE_UNLOADING_TRACK,
	GAMEFLOW_STATE_UNLOADING_REGION,
	GAMEFLOW_STATE_EXIT_DEMO_DISC
};

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