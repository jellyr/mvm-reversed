/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: vision component
 */


class IVision : public INextBotComponent
{
public:
	class IForEachKnownEntity
	{
	public:
		virtual bool Inspect(const CKnownEntity& known) = 0;
	};
	
	enum class FieldOfViewCheckType : int
	{
		USE_FOV       = 0,
		DISREGARD_FOV = 1,
	};
	
	IVision(INextBot *nextbot);
	virtual ~IVision();
	
	virtual void Reset() override;
	virtual void Update() override;
	
	virtual bool ForEachKnownEntity(IForEachKnownEntity& functor);
	virtual void CollectKnownEntities(CUtlVector<CKnownEntity> *knowns);
	virtual const CKnownEntity *GetPrimaryKnownThreat(bool b1) const;
	virtual float GetTimeSinceVisible(int index) const;
	virtual const CKnownEntity *GetClosestKnown(int i1) const;
	virtual int GetKnownCount(int i1, bool b1, float f1) const;
	virtual const CKnownEntity *GetClosestKnown(const INextBotEntityFilter& filter) const;
	virtual const CKnownEntity *GetKnown(const CBaseEntity *ent) const;
	virtual void AddKnownEntity(CBaseEntity *ent);
	virtual void ForgetEntity(CBaseEntity *ent);
	virtual void ForgetAllKnownEntities();
	virtual void CollectPotentiallyVisibleEntities(CUtlVector<CBaseEntity *> *ents);
	virtual float GetMaxVisionRange() const;
	virtual float GetMinRecognizeTime() const;
	virtual bool IsAbleToSee(CBaseEntity *ent, FieldOfViewCheckType ctype, Vector *v1) const;
	virtual bool IsAbleToSee(const Vector& vec, FieldOfViewCheckType ctype) const;
	virtual bool IsIgnored(CBaseEntity *ent) const;
	virtual bool IsVisibleEntityNoticed(CBaseEntity *ent) const;
	virtual bool IsInFieldOfView(const Vector& vec) const;
	virtual bool IsInFieldOfView(CBaseEntity *ent) const;
	virtual float GetDefaultFieldOfView() const;
	virtual float GetFieldOfView() const;
	virtual void SetFieldOfView(float fov);
	virtual bool IsLineOfSightClear(const Vector& v1) const;
	virtual bool IsLineOfSightClearToEntity(const CBaseEntity *ent, Vector *v1) const;
	virtual bool IsLookingAt(const Vector& v1, float cos_half_fov) const;
	virtual bool IsLookingAt(const CBaseCombatCharacter *who, float cos_half_fov) const;
	
protected:
	// 0x14 CountdownTimer
	float m_flFOV;        // +0x20
	float m_flCosHalfFOV; // +0x24
	CUtlVector<CKnownEntity> m_KnownEntities; // +0x28
	// 0x3c dword -1
	// 0x40
	IntervalTimer m_Timers[32];
};


class CDisableVision : public IVision
{
	// TODO
};


// sizeof: 0xf0
class CTFBotVision : public IVision
{
	// TODO
};