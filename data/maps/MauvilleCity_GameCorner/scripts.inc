MauvilleCity_GameCorner_MapScripts:: @ 820FBB8
	.byte 0

    @ Game Corner prices
	.set PORYGON_COINS,  	10
	.set MUNCHLAX_COINS,  	10
	.set VULPIX_COINS,  	10
	.set SANDSHREW_COINS,  	10
	.set RATTATA_COINS,  	10
	.set MEOWTH_COINS,  	10
	.set GRIMER_COINS,  	10
	.set DIGLETT_COINS,  	10
	.set GEODUDE_COINS,  	10
	.set RAICHU_COINS,  	10
	.set MAROWAK_COINS,  	10
	.set EXEGGUTOR_COINS,  	10
	.set STARTER_COINS, 	10
	.set DOLL_COINS,  		10

	.set COINS_PRICE_50,    500
	.set COINS_PRICE_500,   5000
	.set COINS_PRICE_5000,  50000

MauvilleCity_GameCorner_EventScript_CoinsClerk:: @ 820FBB9
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50:: @ 820FBE5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500:: @ 820FC0C
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins:: @ 820FC33
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1 - 50)
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins:: @ 820FC75
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1 - 500)
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy5000Coins::
	setvar VAR_0x8005, COINS_PRICE_5000
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1 - 5000)
	goto_if_ge MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 5000
	special SubtractMoneyFromVar0x8005
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase:: @ 820FCB7
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney:: @ 820FCC1
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins:: @ 820FCD1
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins:: @ 820FCE1
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls:: @ 820FCF1
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage:: @ 820FD0D
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize:: @ 820FD20
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize:: @ 820FD2B
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll:: @ 820FD67
	setvar VAR_TEMP_1, 1
	bufferdecorationname 0, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll:: @ 820FD75
	setvar VAR_TEMP_1, 2
	bufferdecorationname 0, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll:: @ 820FD83
	setvar VAR_TEMP_1, 3
	bufferdecorationname 0, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize:: @ 820FD91
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll:: @ 820FDCB
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll:: @ 820FE05
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll:: @ 820FE3F
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, DOLL_COINS
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll:: @ 820FE79
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll:: @ 820FE87
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect:: @ 820FE92
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Rare Pokemon Prizes @@@@@@@@@@@@@@@@@@@@@@@@@@@@@

MauvilleCity_GameCorner_EventScript_PrizeCornerPokemon::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPokemon
	waitmessage
	setvar VAR_0x8004, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize

MauvilleCity_GameCorner_EventScript_ChoosePokemonPrize::
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_POKEMON
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Porygon
	case 1, MauvilleCity_GameCorner_EventScript_Munchlax
	case 2, MauvilleCity_GameCorner_EventScript_Vulpix
	case 3, MauvilleCity_GameCorner_EventScript_Sandshrew
	case 4, MauvilleCity_GameCorner_EventScript_Rattata
	case 5, MauvilleCity_GameCorner_EventScript_Meowth
	case 6, MauvilleCity_GameCorner_EventScript_Grimer
	case 7, MauvilleCity_GameCorner_EventScript_Diglett
	case 8, MauvilleCity_GameCorner_EventScript_Geodude
	case 9, MauvilleCity_GameCorner_EventScript_Raichu
	case 10, MauvilleCity_GameCorner_EventScript_Marowak
	case 11, MauvilleCity_GameCorner_EventScript_Exeggutor
	case 12, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_Porygon::
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_0x8006, PORYGON_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Munchlax::
	setvar VAR_TEMP_1, SPECIES_MUNCHLAX
	setvar VAR_0x8006, MUNCHLAX_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Vulpix::
	setvar VAR_TEMP_1, SPECIES_VULPIX_ALOLAN
	setvar VAR_0x8006, VULPIX_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Sandshrew::
	setvar VAR_TEMP_1, SPECIES_SANDSHREW_ALOLAN
	setvar VAR_0x8006, SANDSHREW_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Rattata::
	setvar VAR_TEMP_1, SPECIES_RATTATA_ALOLAN
	setvar VAR_0x8006, RATTATA_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Meowth::
	setvar VAR_TEMP_1, SPECIES_MEOWTH_ALOLAN
	setvar VAR_0x8006, MEOWTH_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Grimer::
	setvar VAR_TEMP_1, SPECIES_GRIMER_ALOLAN
	setvar VAR_0x8006, GRIMER_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Diglett::
	setvar VAR_TEMP_1, SPECIES_DIGLETT_ALOLAN
	setvar VAR_0x8006, DIGLETT_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Geodude::
	setvar VAR_TEMP_1, SPECIES_GEODUDE_ALOLAN
	setvar VAR_0x8006, GEODUDE_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Raichu::
	setvar VAR_TEMP_1, SPECIES_RAICHU_ALOLAN
	setvar VAR_0x8006, RAICHU_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Marowak::
	setvar VAR_TEMP_1, SPECIES_MAROWAK_ALOLAN
	setvar VAR_0x8006, MAROWAK_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_Exeggutor::
	setvar VAR_TEMP_1, SPECIES_EXEGGUTOR_ALOLAN
	setvar VAR_0x8006, EXEGGUTOR_COINS
	goto MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize

MauvilleCity_GameCorner_EventScript_ConfirmPokemonPrize::
	bufferspeciesname 0, VAR_TEMP_1
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	checkcoins VAR_0x8007
	compare VAR_0x8007, VAR_0x8006
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon
	goto MauvilleCity_GameCorner_EventScript_ReceivePokemon

MauvilleCity_GameCorner_EventScript_CancelPokemonSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForPokemon::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChoosePokemonPrizeMessage
	end

MauvilleCity_GameCorner_EventScript_ReceivePokemon::
	msgbox MauvilleCity_GameCorner_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	removecoins VAR_0x8006
	updatecoinsbox 1, 1
	special GetStaticEncounterLevel
	givemon VAR_TEMP_1, VAR_0x800A, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReceivePokemonParty
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_ReceivePokemonPC
	goto Common_EventScript_NoMoreRoomForPokemon

MauvilleCity_GameCorner_EventScript_ReceivePokemonParty::
	call MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon

MauvilleCity_GameCorner_EventScript_ReceivePokemonPC::
	call MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_SendPokemonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MauvilleCity_GameCorner_EventScript_SendPokemonToPC

MauvilleCity_GameCorner_EventScript_SendPokemonToPC::
	call Common_EventScript_TransferredToPC
	goto MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon

MauvilleCity_GameCorner_EventScript_ReceivedPokemonFanfare::
	bufferspeciesname 0, VAR_TEMP_1
	playfanfare MUS_OBTAIN_ITEM
	message MauvilleCity_GameCorner_Text_PlayerReceivedPokemon
	waitmessage
	waitfanfare
	@ bufferspeciesname 0, VAR_TEMP_1
	return

MauvilleCity_GameCorner_EventScript_TakeCareOfPokemon::
	bufferspeciesname 0, VAR_TEMP_1
	msgbox MauvilleCity_GameCorner_Text_TakeCareOfPokemon, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Starter Pokemon Prizes @@@@@@@@@@@@@@@@@@@@@@@@@@@@

MauvilleCity_GameCorner_EventScript_PrizeCornerStarter::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichStarterType
	waitmessage
	setvar VAR_0x8004, 0
	showcoinsbox 1, 1
	multichoice 0, 0, MULTI_GRASS_FIRE_WATER, 0
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_ChooseGrassStarter
	case 1, MauvilleCity_GameCorner_EventScript_ChooseFireStarter
	case 2, MauvilleCity_GameCorner_EventScript_ChooseWaterStarter
	case 3, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	case MULTI_B_PRESSED, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_ChooseGrassStarter::
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_GRASS_STARTERS
	setvar VAR_0x8006, STARTER_COINS
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Bulbasaur
	case 1, MauvilleCity_GameCorner_EventScript_Chikorita
	case 2, MauvilleCity_GameCorner_EventScript_Treecko
	case 3, MauvilleCity_GameCorner_EventScript_Turtwig
	case 4, MauvilleCity_GameCorner_EventScript_Snivy
	case 5, MauvilleCity_GameCorner_EventScript_Chespin
	case 6, MauvilleCity_GameCorner_EventScript_Rowlet
	case 7, MauvilleCity_GameCorner_EventScript_Grookey
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_ChooseFireStarter::
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_FIRE_STARTERS
	setvar VAR_0x8006, STARTER_COINS
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Charmander
	case 1, MauvilleCity_GameCorner_EventScript_Cyndaquil
	case 2, MauvilleCity_GameCorner_EventScript_Torchic
	case 3, MauvilleCity_GameCorner_EventScript_Chimchar
	case 4, MauvilleCity_GameCorner_EventScript_Tepig
	case 5, MauvilleCity_GameCorner_EventScript_Fennekin
	case 6, MauvilleCity_GameCorner_EventScript_Litten
	case 7, MauvilleCity_GameCorner_EventScript_Scorbunny
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_ChooseWaterStarter::
	setvar VAR_0x8004, SCROLL_MULTI_GAMECORNER_WATER_STARTERS
	setvar VAR_0x8006, STARTER_COINS
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Squirtle
	case 1, MauvilleCity_GameCorner_EventScript_Totodile
	case 2, MauvilleCity_GameCorner_EventScript_Mudkip
	case 3, MauvilleCity_GameCorner_EventScript_Piplup
	case 4, MauvilleCity_GameCorner_EventScript_Oshawott
	case 5, MauvilleCity_GameCorner_EventScript_Froakie
	case 6, MauvilleCity_GameCorner_EventScript_Popplio
	case 7, MauvilleCity_GameCorner_EventScript_Sobble
	case 8, MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	goto MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	end

MauvilleCity_GameCorner_EventScript_Bulbasaur::
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Chikorita::
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Treecko::
	setvar VAR_TEMP_1, SPECIES_TREECKO
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Turtwig::
	setvar VAR_TEMP_1, SPECIES_TURTWIG
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Snivy::
	setvar VAR_TEMP_1, SPECIES_SNIVY
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Chespin::
	setvar VAR_TEMP_1, SPECIES_CHESPIN
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Rowlet::
	setvar VAR_TEMP_1, SPECIES_ROWLET
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Grookey::
	setvar VAR_TEMP_1, SPECIES_GROOKEY
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Charmander::
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Cyndaquil::
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Torchic::
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Chimchar::
	setvar VAR_TEMP_1, SPECIES_CHIMCHAR
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Tepig::
	setvar VAR_TEMP_1, SPECIES_TEPIG
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Fennekin::
	setvar VAR_TEMP_1, SPECIES_FENNEKIN
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Litten::
	setvar VAR_TEMP_1, SPECIES_LITTEN
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Squirtle::
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Totodile::
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Mudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Piplup::
	setvar VAR_TEMP_1, SPECIES_PIPLUP
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Oshawott::
	setvar VAR_TEMP_1, SPECIES_OSHAWOTT
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Froakie::
	setvar VAR_TEMP_1, SPECIES_FROAKIE
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Popplio::
	setvar VAR_TEMP_1, SPECIES_POPPLIO
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Scorbunny::
	setvar VAR_TEMP_1, SPECIES_SCORBUNNY
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_Sobble::
	setvar VAR_TEMP_1, SPECIES_SOBBLE
	goto MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize

MauvilleCity_GameCorner_EventScript_ConfirmStarterPrize::
	bufferspeciesname 0, VAR_TEMP_1
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_CancelPokemonSelect
	checkcoins VAR_0x8007
	compare VAR_0x8007, VAR_0x8006
	goto_if_lt MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter
	goto MauvilleCity_GameCorner_EventScript_ReceivePokemon

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForStarter::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseStarterPrizeMessage
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


MauvilleCity_GameCorner_EventScript_Woman2:: @ 8210125
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman:: @ 821012E
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl:: @ 8210137
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll:: @ 821017C
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll:: @ 82101A6
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll:: @ 82101D0
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll:: @ 82101FA
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll:: @ 8210209
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll:: @ 8210213
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM:: @ 821021D
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins:: @ 821023D
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 1  @ Only give 20 coins if player has no coins
	goto_if_ge MauvilleCity_GameCorner_EventScript_PokefanMNormal
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal:: @ 821026B
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan:: @ 8210279
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook:: @ 8210289
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man:: @ 8210299
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots:: @ 82102A9
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac:: @ 82102B6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman:: @ 82102C6
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0:: @ 82102D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1:: @ 82102F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2:: @ 8210316
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3:: @ 8210336
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4:: @ 8210356
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5:: @ 8210376
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6:: @ 8210396
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7:: @ 82103B6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8:: @ 82103D6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9:: @ 82103F6
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10:: @ 8210416
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11:: @ 8210436
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase:: @ 8210456
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner: @ 8210460
	.string "This is Mauville Game Corner.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins: @ 821047E
	.string "Okay, you wanted some Coins for\n"
	.string "the games?\p"
	.string "But you don't have a Coin Case for\n"
	.string "stowing the Coins.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins: @ 82104DF
	.string "Were you looking for Coins?\p"
	.string "It's ¥500 for 50 Coins.\n"
	.string "Would you like some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins: @ 8210529
	.string "Thank you very much!\n"
	.string "Here are your Coins!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney: @ 8210553
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull: @ 821057E
	.string "Oh?\n"
	.string "Your Coin Case is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen: @ 821059A
	.string "Oh… You don't need Coins, then?\n"
	.string "Good luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes: @ 82105D7
	.string "Welcome.\p"
	.string "You can exchange your Coins for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize: @ 821060D
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC: @ 8210646
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins: @ 8210673
	.string "You don't have enough Coins.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor: @ 8210690
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo: @ 82106BF
	.string "Oh, is that so? \n"
	.string "You need to save some Coins before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX: @ 8210705
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo: @ 821071B
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPokemon:
	.string "Welcome.\p"
	.string "You can exchange your Coins for\n"
	.string "rare Pokémon here.$"

MauvilleCity_GameCorner_Text_WhichPokemon:
	.string "Which Pokémon would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsThePokemonX:
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_ThanksPleaseTakePokemon:
	.string "Thank you!\p"
	.string "Please take your new Pokémon.$"

MauvilleCity_GameCorner_Text_PlayerReceivedPokemon:
	.string "{PLAYER} received {STR_VAR_1}!$"

MauvilleCity_GameCorner_Text_TakeCareOfPokemon:
	.string "Take good care of {STR_VAR_1}!$"

MauvilleCity_GameCorner_Text_WhichStarterType:
	.string "Which Type of Pokémon would you like?$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore: @ 8210728
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne: @ 8210750
	.string "I made a mistake and got two of\n"
	.string "the same Dolls.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2: @ 821079C
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow: @ 82107A9
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative: @ 82107CE
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot: @ 82107FB
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor: @ 8210830
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a Coin Case.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins: @ 82108A0
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some Coins!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone: @ 82108EF
	.string "Mauville has something for\n"
	.string "everyone.\p"
	.string "For me, it's the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates: @ 8210932
	.string "The Roulette tables have different\n"
	.string "rates.\p"
	.string "Check your Coins if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime: @ 821098E
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay: @ 82109D3
	.string "Coins are needed to play here\n"
	.string "in the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck: @ 8210A05
	.string "This Roulette thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed: @ 8210A51
	.string "Up to three Coins can be used to play\n"
	.string "the Slots.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7: @ 8210A82
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the Reel Time\n"
	.string "bonus game, you'll receive extra Coins.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo: @ 8210B04
	.string "Here's some information for you\n"
	.string "about the Slots.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more Reel Time chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "Reel Time chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 Coins, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase: @ 8210C2E
	.string "You can't play if you don't have\n"
	.string "a Coin Case.$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_2
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1:
	release
	end

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_2:
	checktrainerflag TRAINER_SINNOH_MEGAS_MAUVILLE_GAME_CORNER
	goto_if 0, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_5
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_5:
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_8
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_8:
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_SINNOH_MEGAS_MAUVILLE_GAME_CORNER, MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_2
	msgbox MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INFERNAPENITE, 1
	giveitem ITEM_TORTERRANITE, 1
	giveitem ITEM_EMPOLEONITE, 1
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_1


MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_0:
	.string "FUCK YOU???$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_1:
	.string "FUCK YOU!!!$"

MauvilleCity_GameCorner_EventScript_SinnohMegas_Battle_Text_2:
	.string "FUCK ME???$"
