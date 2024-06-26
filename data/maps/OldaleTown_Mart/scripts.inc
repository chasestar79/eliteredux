OldaleTown_Mart_MapScripts:: @ 81FC23F
	.byte 0

OldaleTown_Mart_EventScript_Woman:: @ 81FC28A
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock:: @ 81FC29F
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy:: @ 81FC2A9
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut: @ 81FC2B2
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any Poké Balls.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls: @ 81FC2F3
	.string "I'm going to buy a bunch of Poké Balls\n"
	.string "and catch a bunch of Pokémon!$"

OldaleTown_Mart_Text_RestoreHPWithPotion: @ 81FC338
	.string "If a Pokémon gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your Pokémon from fainting,\n"
	.string "restore its HP with a Potion.$"
