/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_point/tf_bot_defend_point.h
 * used in MvM: TODO
 */


// sizeof: 0x9034
class CTFBotDefendPoint : public Action<CTFBot>
{
public:
	CTFBotDefendPoint(/* TODO */);
	virtual ~CTFBotDefendPoint();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnTerritoryContested(CTFBot *actor, int i1) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryCaptured(CTFBot *actor, int i1) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
private:
	bool IsPointThreatened(CTFBot *actor);
	UNKNOWN SelectAreaToDefendFrom(CTFBot *actor);
	bool WillBlockCapture(CTFBot *actor) const;
	
	// TODO
};


// NOTE: ISearchSurroundingAreasFunctor is in the public SDK

// TODO: CSelectDefenseAreaForPoint