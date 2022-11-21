class UIEditor extends UIScriptedMenu
{
	
    private bool                 m_Initialized;
    private bool                 m_IsMenuOpen;
	private Widget				 layoutRoot;

    //---Elements from .layout file

private TextWidget                  m_label_title;
private ButtonWidget                m_button_close;
private ImageWidget                 m_ImageWidget0;
private ButtonWidget                m_newframe_button;
private ButtonWidget                m_previousframe_button;
private ButtonWidget                m_nextframe_button;
private ButtonWidget                m_saveframe_button;
private ButtonWidget                m_deleteframe_button;
private ButtonWidget                m_prevportrait_button;
private ButtonWidget                m_nextportrait_button;
private ImageWidget                 m_portrait_image;
private ButtonWidget                m_dlgadd_button;
private ButtonWidget                m_dlgdelete_button;
private ButtonWidget                m_dlgcondition_button;
private MultilineEditBoxWidget      m_MultilineEditBoxWidget0;
private ButtonWidget                m_nextdlg_button;
private ButtonWidget                m_prevdlg_button;
private ButtonWidget                m_responseadd_button;
private ButtonWidget                m_responsedelete_button;
private ScrollWidget                m_ScrollWidget0;
private ButtonWidget                m_filenew_button;
private ButtonWidget                m_fileopen_button;
private ButtonWidget                m_filesave_button;
private ButtonWidget                m_fileclose_button;
		
    //---

    //Array that stores child widgets we create during runtime
    //private ref array<ref Widget> m_CustomChildrenHighIQ;

    void UIEditor()
    {
		
    }

    /*
		This is the destructor, called when this class is deleted / destroyed
    */
    void ~UIEditor() 
    {
        PPEffects.SetBlurMenu( 0 );
        GetGame().GetUIManager().Back();
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );

        //Destroy root widget and all its children
        if ( layoutRoot )
        	layoutRoot.Unlink();
    }

    //after show
    override void OnShow()
    {
        super.OnShow();
		KPMenuUtils.LockControls();
        PPEffects.SetBlurMenu( 0.5 ); //Add blurr effect


		
		
    }

    //after hide
    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurMenu( 0 ); //Remove blurr effect
		KPMenuUtils.UnlockControls();


        //Unlock controls, this also happens in missionGameplay.c however including it here will assure control is gained back incase that method is not invoked. 
        //That can occur when other mods / scripts force a menu on screen illegally 


		
		// GetParentMenu().EnterScriptedMenu(UI_ADMIN_CONTROL);

    }

    override Widget Init()
    {
        if (!m_Initialized) //Only draw and init widgets if not already done that, since this function is called each time you do ( ShowScriptedMenu() )
        {
            layoutRoot = GetGame().GetWorkspace().CreateWidgets( "NPCPro/NPCPro_scripts/GUI/Layouts/UIEditor.layout");
            
            //Define elements from .layout ( you must cast each element to its according script class if you wish to use its functions see scripts\1_Core\proto\EnWidgets.c )

			m_label_title                       =   TextWidget.Cast(layoutroot.FindAnyWidget("label_title"));
			m_button_close                      =   ButtonWidget.Cast(layoutroot.FindAnyWidget("button_close"));
			m_ImageWidget0                      =   ImageWidget.Cast(layoutroot.FindAnyWidget("ImageWidget0"));
			m_newframe_button                   =   ButtonWidget.Cast(layoutroot.FindAnyWidget("newframe_button"));
			m_previousframe_button              =   ButtonWidget.Cast(layoutroot.FindAnyWidget("previousframe_button"));
			m_nextframe_button                  =   ButtonWidget.Cast(layoutroot.FindAnyWidget("nextframe_button"));
			m_saveframe_button                  =   ButtonWidget.Cast(layoutroot.FindAnyWidget("saveframe_button"));
			m_deleteframe_button                =   ButtonWidget.Cast(layoutroot.FindAnyWidget("deleteframe_button"));
			m_prevportrait_button               =   ButtonWidget.Cast(layoutroot.FindAnyWidget("prevportrait_button"));
			m_nextportrait_button               =   ButtonWidget.Cast(layoutroot.FindAnyWidget("nextportrait_button"));
			m_portrait_image                    =   ImageWidget.Cast(layoutroot.FindAnyWidget("portrait_image"));
			m_dlgadd_button                     =   ButtonWidget.Cast(layoutroot.FindAnyWidget("dlgadd_button"));
			m_dlgdelete_button                  =   ButtonWidget.Cast(layoutroot.FindAnyWidget("dlgdelete_button"));
			m_dlgcondition_button               =   ButtonWidget.Cast(layoutroot.FindAnyWidget("dlgcondition_button"));
			m_MultilineEditBoxWidget0           =   MultilineEditBoxWidget.Cast(layoutroot.FindAnyWidget("MultilineEditBoxWidget0"));
			m_nextdlg_button                    =   ButtonWidget.Cast(layoutroot.FindAnyWidget("nextdlg_button"));
			m_prevdlg_button                    =   ButtonWidget.Cast(layoutroot.FindAnyWidget("prevdlg_button"));
			m_responseadd_button                =   ButtonWidget.Cast(layoutroot.FindAnyWidget("responseadd_button"));
			m_responsedelete_button             =   ButtonWidget.Cast(layoutroot.FindAnyWidget("responsedelete_button"));
			m_ScrollWidget0                     =   ScrollWidget.Cast(layoutroot.FindAnyWidget("ScrollWidget0"));
			m_filenew_button                    =   ButtonWidget.Cast(layoutroot.FindAnyWidget("filenew_button"));
			m_fileopen_button                   =   ButtonWidget.Cast(layoutroot.FindAnyWidget("fileopen_button"));
			m_filesave_button                   =   ButtonWidget.Cast(layoutroot.FindAnyWidget("filesave_button"));
			m_fileclose_button                  =   ButtonWidget.Cast(layoutroot.FindAnyWidget("fileclose_button"));
			

									
          //  WidgetEventHandler.GetInstance().RegisterOnDoubleClick( m_Grid, this, "OnDoubleClicked" ); //Attach a double-click event on a specifc widget
          //  WidgetEventHandler.GetInstance().RegisterOnDoubleClick( m_Scroller, this, "OnDoubleClicked" );

            m_Initialized = true;
        }
        return layoutRoot;
    }

   

    //Called on each frame, this will be paused when the menu is hidden or missiongameplay callqueue is frozen / paused
    override void Update(float timeslice)
    {
        super.Update(timeslice);

    }

    // Click event triggers when you click on a widget, this method wont get called if your widget has the "IgnorePointer" property toggled in your .layout
    override bool OnClick(Widget w, int x, int y, int button)
    {
    	switch(w)
		{
			case m_rootPanel:
		
				//  Your code goes here
		
			break;
		
			case m_titlebar_panel:
		
				//  Your code goes here
		
			break;
		
			case m_label_title:
		
				//  Your code goes here
		
			break;
		
			case m_panel_close:
		
				//  Your code goes here
		
			break;
		
			case m_button_close:
		
				//  Your code goes here
		
			break;
		
			case m_ImageWidget0:
		
				//  Your code goes here
		
			break;
		
			case m_frameeditor_panel:
		
				//  Your code goes here
		
			break;
		
			case m_framnav_panel:
		
				//  Your code goes here
		
			break;
		
			case m_newframe_button:
		
				//  Your code goes here
		
			break;
		
			case m_previousframe_button:
		
				//  Your code goes here
		
			break;
		
			case m_nextframe_button:
		
				//  Your code goes here
		
			break;
		
			case m_saveframe_button:
		
				//  Your code goes here
		
			break;
		
			case m_deleteframe_button:
		
				//  Your code goes here
		
			break;
		
			case m_frame_panel:
		
				//  Your code goes here
		
			break;
		
			case m_top_panel:
		
				//  Your code goes here
		
			break;
		
			case m_portrait_panel:
		
				//  Your code goes here
		
			break;
		
			case m_portraitcontrol_panel:
		
				//  Your code goes here
		
			break;
		
			case m_prevportrait_button:
		
				//  Your code goes here
		
			break;
		
			case m_nextportrait_button:
		
				//  Your code goes here
		
			break;
		
			case m_portraitcontainer_panel:
		
				//  Your code goes here
		
			break;
		
			case m_portrait_image:
		
				//  Your code goes here
		
			break;
		
			case m_dialog_panel:
		
				//  Your code goes here
		
			break;
		
			case m_dialogcontrol_panel:
		
				//  Your code goes here
		
			break;
		
			case m_dlgadd_button:
		
				//  Your code goes here
		
			break;
		
			case m_dlgdelete_button:
		
				//  Your code goes here
		
			break;
		
			case m_dlgcondition_button:
		
				//  Your code goes here
		
			break;
		
			case m_dialogcontainer_panel:
		
				//  Your code goes here
		
			break;
		
			case m_MultilineEditBoxWidget0:
		
				//  Your code goes here
		
			break;
		
			case m_dlgnav_panel:
		
				//  Your code goes here
		
			break;
		
			case m_nextdlg_button:
		
				//  Your code goes here
		
			break;
		
			case m_prevdlg_button:
		
				//  Your code goes here
		
			break;
		
			case m_bottom_panel:
		
				//  Your code goes here
		
			break;
		
			case m_responsecontrol_panel:
		
				//  Your code goes here
		
			break;
		
			case m_responseadd_button:
		
				//  Your code goes here
		
			break;
		
			case m_responsedelete_button:
		
				//  Your code goes here
		
			break;
		
			case m_responsecontent_panel:
		
				//  Your code goes here
		
			break;
		
			case m_responsescroll_panel:
		
				//  Your code goes here
		
			break;
		
			case m_ScrollWidget0:
		
				//  Your code goes here
		
			break;
		
			case m_controls_panel:
		
				//  Your code goes here
		
			break;
		
			case m_filenew_button:
		
				//  Your code goes here
		
			break;
		
			case m_fileopen_button:
		
				//  Your code goes here
		
			break;
		
			case m_filesave_button:
		
				//  Your code goes here
		
			break;
		
			case m_fileclose_button:
		
				//  Your code goes here
		
			break;
		
		}

        return super.OnClick(w, x, y, button);
    }

    //Called by WidgetEventHandler that is registered at line 70 ( more of these examples can be found in vanilla scripts / menus creates by devs )
    void OnDoubleClicked(Widget w, int x, int y, int button) 
    {
        if (button == MouseState.LEFT)
        {
            //Do something
        }
        else if (button == MouseState.RIGHT)
        {
            //Do something
        }
    }

    bool IsMenuOpen() 
    {
        return m_IsMenuOpen;
    }

    void SetMenuOpen(bool isMenuOpen) 
    {
        m_IsMenuOpen = isMenuOpen;
        if (m_IsMenuOpen)
            PPEffects.SetBlurMenu( 0.5 );
        else
            PPEffects.SetBlurMenu( 0 );
    }
};