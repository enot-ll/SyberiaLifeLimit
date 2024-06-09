modded class MissionMainMenu
{
	private ref WatermarkHandler m_watermarkHandler;
	
    override void OnMissionStart()
	{
		super.OnMissionStart();
		
		m_watermarkHandler = new WatermarkHandler();
		ref Widget rootWidget = m_mainmenu.GetLayoutRoot().FindAnyWidget( "vignette" );
		if (!rootWidget)
		{
			rootWidget = m_mainmenu.GetLayoutRoot();
		}
		
		ref Widget watermarkWidget = GetGame().GetWorkspace().CreateWidgets( "SyberiaLifeLimit/layout/WatermarkMain.layout" );		
		ref Widget watermarkBase = watermarkWidget.FindAnyWidget( "WatermarkBase" );
		ref Widget watermarkBtn = watermarkBase.FindAnyWidget( "WatermarkActionBtn" );
		m_WidgetEventHandler.RegisterOnClick(watermarkBtn, m_watermarkHandler, "OnWatermarkClick");
		watermarkWidget.RemoveChild(watermarkBase);
		rootWidget.AddChild(watermarkBase, true);
		delete watermarkWidget;
	}
};