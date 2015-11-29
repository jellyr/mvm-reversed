/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: chase path
 */


class ChasePath : public PathFollower
{
public:
	ChasePath();
	virtual ~ChasePath();
	
	virtual void Invalidate() override;
	
	virtual void Update(INextBot *nextbot, CBaseEntity *ent, const IPathCost& cost_func, Vector *v1);
	virtual float GetLeadRadius() const;
	virtual float GetMaxPathLength() const;
	virtual Vector PredictSubjectPosition(INextBot *nextbot, CBaseEntity *ent) const;
	virtual bool IsRepathNeeded(INextBot *nextbot, CBaseEntity *ent) const;
	virtual float GetLifetime() const;
	
	void RefreshPath(INextBot *nextbot, CBaseEntity *ent, const IPathCost& cost_func, Vector *v1);
	
protected:
	CountdownTimer m_ctTimer1; // +0x47d4
	CountdownTimer m_ctTimer2; // +0x47e0
	CountdownTimer m_ctTimer3; // +0x47ec
	// 47f8 dword -1
	// 47fc dword 0 or possibly 1
	CountdownTimer m_ctTimer4; // +0x4800
};

// TODO: struct and vtable in IDA

// TODO: look at DirectChasePath
