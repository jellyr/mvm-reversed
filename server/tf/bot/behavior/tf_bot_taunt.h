/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_taunt.h
 * used in MvM: TODO
 */


// sizeof: 0x50
class CTFBotTaunt : public Action<CTFBot>
{
public:
	CTFBotTaunt();
	virtual ~CTFBotTaunt();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	CountdownTimer m_ctStart;  // +0x34
	CountdownTimer m_ctTimer2; // +0x40
	bool m_bStartedTaunting;   // +0x4c
};