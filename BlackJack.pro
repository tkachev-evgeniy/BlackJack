TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        card.cpp \
        deck.cpp \
        game.cpp \
        generic_player.cpp \
        hand.cpp \
        house.cpp \
        main.cpp \
        player.cpp

HEADERS += \
	Ranks.h \
	card.h \
	deck.h \
	game.h \
	generic_player.h \
	hand.h \
	house.h \
	player.h
