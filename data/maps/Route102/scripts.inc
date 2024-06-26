Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_LittleBoy:: @ 81EC0E1
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale:: @ 81EC0EA
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy:: @ 81EC0FC
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Oldplayer::
	trainerbattle_no_intro TRAINER_OLDPLAYER, Route102_Text_CalvinDefeated
	release
	end


Route102_EventScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister:: @ 81EC183
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "Wally: {PLAYER}…\n"
	.string "Pokémon hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "Go, Zigzagoon!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "Wally: Come on, Poké Ball!\n"
	.string "Just shake a few more times...\p"
	.string "...\p"
	.string "Wally: Yes! I did it… It's my…\n"
	.string "My first Pokémon!\p"
	.string "I'll never forget this moment!$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the Gym!$"

Route102_Text_ImNotVeryTall: @ 81EC2C0
	.string "I'm… not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "Pokémon!$"

Route102_Text_RouteSignOldale: @ 81EC35B
	.string "Route 102\n"
	.string "{RIGHT_ARROW} Oldale Town$"

Route102_Text_RouteSignPetalburg: @ 81EC373
	.string "Route 102\n"
	.string "{LEFT_ARROW} Petalburg City$"

Route102_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_CALVIN_1
	goto_if 1, Route102_EventScript_Gen8_NPC_5
Route102_EventScript_Gen8_NPC_3:
	msgbox Route102_EventScript_Gen8_NPC_Text_2
Route102_EventScript_Gen8_NPC_1:
	release
	end

Route102_EventScript_Gen8_NPC_2:
	msgbox Route102_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_ROOKIDEE, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route102_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route102_EventScript_Gen8_NPC_1

Route102_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_ALLEN
	goto_if 1, Route102_EventScript_Gen8_NPC_8
	goto Route102_EventScript_Gen8_NPC_3

Route102_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_RICK
	goto_if 1, Route102_EventScript_Gen8_NPC_4
	goto Route102_EventScript_Gen8_NPC_3

Route102_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_TIANA
	goto_if 1, Route102_EventScript_Gen8_NPC_2
	goto Route102_EventScript_Gen8_NPC_3


Route102_EventScript_Gen8_NPC_Text_0:
	.string "Great job winning those battles! Take\n"
	.string "this Pokémon from Galar, you can have\l"
	.string "as many of them as you like!$"

Route102_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Rookidee{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route102_EventScript_Gen8_NPC_Text_2:
	.string "Hey there, fellow trainer! Have you\n"
	.string "heard about the exciting promotion\l"
	.string "we're running? We're students from\l"
	.string "Galar, and we've traveled all the way to\l"
	.string "beautiful Hoenn to show off the\l"
	.string "awesomeness of our home region and its\l"
	.string "incredible Pokémons. If you defeat\l"
	.string "every trainer in a route and speak to\l"
	.string "us, we'll gladly give you one, free of\l"
	.string "charge!$"
