class ActionReadBookPageCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(30);
	}
};

class ActionReadBook extends ActionContinuousBase
{
	void ReadBook( ItemBase book, PlayerBase player) {}
	void ActionReadBook()
	{
		m_CallbackClass = ActionReadBookPageCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#syb_readbook";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return item && item.IsInherited(ItemBook) && !item.IsRuined();
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if(action_data.m_MainItem && player)
		{
			ReadBook( action_data.m_MainItem, player);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
};