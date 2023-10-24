class TrackInfo
{
public:
	static inline TrackInfo*& LoadedTrackInfo = *(TrackInfo**)0xB69BA0;

	static TrackInfo* GetTrackInfo(uint32_t a1)
	{
		return ((TrackInfo*(__cdecl*)(uint32_t))0x7990C0)(a1);
	}
};

struct RaceParameters
{
	uint32_t TrackNumber;
};
auto& TheRaceParameters = *(RaceParameters*)0xA7A1A8;