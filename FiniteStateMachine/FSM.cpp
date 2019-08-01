//defines for game loop states
#define GAME_INIT
#define GAME_MENU
#define GAME_STARTING
#define GAME_RUN
#define GAME_RESTART
#define GAME_EXIT

//GLOBAL
int game_state = GAME_INIT;
int error      = 0;

//main

void main()
{
    //implementation of main loop
    while(game_state != GAME_EXIT)
    {
        //LOOP IN
        switch(game_state)
        {
            case GAME_INIT:
            {
                //allocate all memory and resources
                Init();

                game_state = GAME_MENU;
            } break;
            case GAME_MENU:
            {
                //call main menu func and let it switch states
                game_state = Menu();
            } break;
            case GAME_STARTING:
            {

                Setup_For_Run();

                game_state = GAME_RUN;
            } break;
            case GAME_RUN:
            {
                Clear();

                Get_Input();

                Do_Logic();

                Render_Frame();

                Wait();

            } break;

            case GAME_RESTART:
            {
                Fixup();

                game_state = GAME_MENU;
            } break;

            case GAME_EXIT:
            {
                Release_And_Cleanup();

                error = 0;

            } break;
        } //end switch

    }

    return(error);
}//end main

