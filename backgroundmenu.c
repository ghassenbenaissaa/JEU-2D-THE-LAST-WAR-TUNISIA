#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
void inittBack(bg *b)
{
    char ch[39];
    int j;
    for(j=1; j<39; j++)
    {
        sprintf(ch,"../Background/logo/%d.png",j);
        b->img[j]=IMG_Load(ch);
    }
    
    b->background = IMG_Load("../Background/game.png");
    b->loadgame_play=IMG_Load("../Background/loadgame_play.png");
    b->newgame_play=IMG_Load("../Background/newgame_play.png");
    b->play=IMG_Load("../Background/play.png");
    b->credit=IMG_Load("../Background/credit.png");
    b->load=IMG_Load("../Background/load.png");
    b->settings=IMG_Load("../Background/settings.png");
    b->sound=IMG_Load("../Background/yes.png");
    b->in_sound=IMG_Load("../Background/volume100.png");
    b->in_sound25=IMG_Load("../Background/volume75.png");
    b->in_sound50=IMG_Load("../Background/volume50.png") ;
    b->in_sound75=IMG_Load("../Background/volume25.png");
    b->in_sound100=IMG_Load("../Background/volume0.png");
    b->in_settings=IMG_Load("../Background/in_settings.png") ;
    b->in_play=IMG_Load("../Background/in_play.png") ;
    b->in_credit=IMG_Load("../Background/in_credit.png");
    b->fullscreen=IMG_Load("../Background/settingsfull.png") ;
    b->normalscreen=IMG_Load("../Background/settingsnormal.png");
    b->back_credit=IMG_Load("../Background/back_credit.png");
    b->back_play=IMG_Load("../Background/back_play.png");
    b->load_play=IMG_Load("../Background/load_play.png");
    b->back_load=IMG_Load("../Background/back_load.png");
    b->back_settings=IMG_Load("../Background/back_settings.png");
    b->quitter=IMG_Load("../Background/exit.png");
    b->wexit=IMG_Load("../Background/ywexit.png") ;
    b->ilbarra=IMG_Load("../Background/multiplaye/ilbara.png") ;
    b->backkk_ilbara=IMG_Load("../Background/multiplaye/backkk.png") ;
    b->multiplay=IMG_Load("../Background/multiplaye/multiplay.png") ;
    b->singeleplayer=IMG_Load("../Background/multiplaye/singeleplayer.png") ;
    b->nwexit=IMG_Load("../Background/nwexit.png") ;
    b->exxit=IMG_Load("../Background/wexit.png") ;
    b->sound=IMG_Load("no.png");
    b->img1=IMG_Load("../Background/img/ph1.png");
    b->img2=IMG_Load("../Background/img/ph2.png");
    b->img3=IMG_Load("../Background/img/ph3.png");
    b->img4=IMG_Load("../Background/img/ph4.png");
    b->img5=IMG_Load("../Background/img/ph5.png");
    b->img6=IMG_Load("../Background/img/ph6.png");
    b->img7=IMG_Load("../Background/img/ph7.png");
    b->img8=IMG_Load("../Background/img/ph8.png");
    b->img9=IMG_Load("../Background/img/ph9.png");
    b->img10=IMG_Load("../Background/img/ph10.png");
    b->img11=IMG_Load("../Background/img/ph11.png");
    b->img12=IMG_Load("../Background/img/ph12.png");
    b->img13=IMG_Load("../Background/img/ph13.png");
    b->img14=IMG_Load("../Background/img/ph14.png");
    b->img15=IMG_Load("../Background/img/ph15.png");
    b->img16=IMG_Load("../Background/img/ph16.png");
    b->img17=IMG_Load("../Background/img/ph17.png");
    b->best_play=IMG_Load("../Background/BESTSCORE.png");
    b->wessetbest=IMG_Load("../Background/wessetbest.png");
    b->backbest=IMG_Load("../Background/backbest.png");

    b->imgp.x=0;
    b->imgp.y=0;

    b->posback.x = 0;
    b->posback.y = 0;

    b->imgggg.x = 0;
    b->imgggg.y = 0;

    b->posba.x = 0;
    b->posba.y = 0;

    b->pos_play.x = 770;
    b->pos_play.y = 464;

    b->pos_credit.x = 774;
    b->pos_credit.y = 702;

    b->pos_settings.x = 773;
    b->pos_settings.y = 583;

    b->pos_sound.x=20 ;
    b->pos_sound.y=50 ;
    
    b->pos_backbest.x=887 ;
    b->pos_backbest.y=924 ;

    b->pos_quitter.x = 773;
    b->pos_quitter.y = 817;

    b->pos_insound.x=808 ;
    b->pos_insound.y=506 ;

    b->pos_fullscreen.x=656 ;
    b->pos_fullscreen.y=680 ;

    b->pos_normalscreen.x=961 ;
    b->pos_normalscreen.y=691 ;

    b->pos_back_credit.x=875;
    b->pos_back_credit.y=908;

    b->pos_newgame_play.x = 740;
    b->pos_newgame_play.y = 368;

    b->pos_loadgame_play.x = 759;
    b->pos_loadgame_play.y = 526;
    
    b->pos_loadgame_best.x = 760;
    b->pos_loadgame_best.y = 686;

    b->pos_back_play.x=879;
    b->pos_back_play.y=944;

    b->pos_back_load.x=711;
    b->pos_back_load.y=916;

    b->pos_load_play.x=1054;
    b->pos_load_play.y=918;

    b->pos_back_settings.x=872 ;
    b->pos_back_settings.y=883 ;

    b->pos_single.x=773 ;
    b->pos_single.y=429 ;

    b->pos_multi.x=773 ;
    b->pos_multi.y=603 ;

    b->pos_backmulti.x=898 ;
    b->pos_backmulti.y=944 ;

    b->pos_yes.x=997 ;
    b->pos_yes.y=704 ;

    b->pos_no.x=549 ;
    b->pos_no.y=704 ;

    b->pos_moins.x=702 ;
    b->pos_moins.y=538 ;

    b->pos_plus.x=1175 ;
    b->pos_plus.y=536 ;


    b->pos_backmulti.x=885 ;
    b->pos_backmulti.y=935 ;

    b->pos_multi.x=732 ;
    b->pos_multi.y=598 ;

    b->pos_single.x=728 ;
    b->pos_single.y=422 ;


}
