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
		m_CallbackClass = ActionSearchTargetInventoryCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
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