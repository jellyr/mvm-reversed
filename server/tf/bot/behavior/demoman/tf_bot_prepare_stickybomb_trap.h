/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/demoman/tf_bot_prepare_stickybomb_trap.h
 * used in MvM: TODO
 */


// sizeof: 0x58
class CTFBotPrepareStickybombTrap : public Action<CTFBot>
{
public:
	// TODO: CTFBotPrepareStickybombTrap::BombTargetArea
	
	CTFBotPrepareStickybombTrap();
	virtual ~CTFBotPrepareStickybombTrap();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnInjured(CTFBot *actor, const CTakeDamageInfo& info) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	static bool IsPossible(CTFBot *actor);
	
private:
	void InitBombTargetAreas(CTFBot *actor);
	
	// TODO
};