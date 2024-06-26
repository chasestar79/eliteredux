VerdanturfTown_WandasHouse_MapScripts:: @ 82028BE
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally:: @ 82028BF
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech:: @ 82028D7
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle:: @ 82028E1
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff:: @ 82028FF
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande:: @ 8202909
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend:: @ 8202913
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite::
	goto_if_set FLAG_WANDA_GARDEVOIRITE, VerdanturfTown_WandasHouse_EventScript_WandaGaveStone
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite, MSGBOX_DEFAULT
	givecustommon SPECIES_GARDEVOIR, 40, ITEM_CHOICE_SCARF, ITEM_POKE_BALL, NATURE_TIMID, 1, 4, 0, 0, 252, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_DAZZLING_GLEAM, MOVE_MYSTICAL_FIRE, MOVE_THUNDERBOLT, MOVE_PSYCHIC, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message VerdanturfTown_WandasHouse_Text_Got_Gardevoir
	waitfanfare
	setflag FLAG_WANDA_GARDEVOIRITE
	msgbox VerdanturfTown_WandasHouse_Text_PrettyStone, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaGaveStone::
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen:: @ 8202975
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened:: @ 820297F
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande:: @ 8202989
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech: @ 8202993
	.string "Wally: I lost to you, {PLAYER}, but I'm\n"
	.string "not feeling down anymore.\p"
	.string "Because I have a new purpose in life.\n"
	.string "Together with my Gardevoir, I'm going\l"
	.string "to challenge Pokémon Gyms and become\l"
	.string "a great Trainer.\p"
	.string "Please watch me, {PLAYER}.\n"
	.string "I'm going to be stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort: @ 8202ABE
	.string "Wally: Please watch me, {PLAYER}.\n"
	.string "I'm going to get stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor: @ 8202B37
	.string "Uncle: Oh! {PLAYER}{KUN}!\n"
	.string "Wally's next door.\p"
	.string "But, boy, there's something I have to\n"
	.string "tell you.\p"
	.string "This natural environment is doing\n"
	.string "wonders for Wally's health.\p"
	.string "Maybe it's not just the environment.\n"
	.string "It could be Pokémon that are giving\l"
	.string "the boy hope.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff: @ 8202C20
	.string "Wally's gone away…\n"
	.string "He slipped off on his own…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar: @ 8202C4E
	.string "Uncle: Is that right?\n"
	.string "Wally's gone away that far all by\l"
	.string "himself…\p"
	.string "Well, I have to give him credit--he is\n"
	.string "my little brother's son.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "Wanda: You are?\n"
	.string "Oh, right, I get it!\p"
	.string "You're the {PLAYER} who Wally was\n"
	.string "telling me about.\p"
	.string "I'm Wally's cousin.\n"
	.string "Glad to meet you!\p"
	.string "I think Wally's become a lot more lively\n"
	.string "and healthy since he came here.$"

VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite:
	.string "I didn't really thank you properly when\n"
	.string "you helped smash those rocks in the\l"
	.string "tunnel.\p"
	.string "I was thinking that I wanted to give\n"
	.string "this {COLOR BLUE}Gardevoir{COLOR DARK_GRAY} to you…$"

VerdanturfTown_WandasHouse_Text_PrettyStone:
	.string "It's a pretty Pokémon, I hope\n"
	.string "you like it as much as I do.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally: @ 8202D91
	.string "Wanda: Don't worry about Wally.\n"
	.string "He'll be just fine.\p"
	.string "I know my little cousin, and he has\n"
	.string "Pokémon with him, too.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay: @ 8202E00
	.string "Thanks to you, I can see my girlfriend\n"
	.string "every day.\l"
	.string "Happy? You bet I am!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven: @ 8202E47
	.string "My daughter's boyfriend is a very\n"
	.string "driven and passionate sort of person.\p"
	.string "He's been digging a tunnel nonstop\n"
	.string "just so he can see my daughter.\p"
	.string "My daughter's a little concerned,\n"
	.string "so she goes out to the tunnel a lot.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging: @ 8202F19
	.string "It's amazing. My daughter's boyfriend\n"
	.string "was digging the tunnel by hand!\p"
	.string "It's so incredible!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally: @ 8202F73
	.string "If anything were to happen to Wally,\n"
	.string "I would never be able to look his\l"
	.string "parents in Petalburg in the eye…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande: @ 8202FDB
	.string "Wally was in Ever Grande?\p"
	.string "His parents in Petalburg would be\n"
	.string "astonished to hear that!$"

VerdanturfTown_WandasHouse_Text_Got_Gardevoir::
	.string "{PLAYER} got a {COLOR BLUE}Gardevoir{COLOR DARK_GRAY} as a gift!$"
