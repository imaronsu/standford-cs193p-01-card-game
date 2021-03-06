//
//  CardMatchingGame.h
//  CardGame
//
//  Created by Daniela on 1/30/13.
//  Copyright (c) 2013 Henry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Deck.h"	

/**
 * A CardMatchingGame object contains all game playing logic. It also caculates score and hold game states.
 *
 **/
@interface CardMatchingGame : NSObject

#define FLIP_PENALTY -1


///---------------------------------------------------------------------------------------
/// @name CardMatchingGame Attributes
///---------------------------------------------------------------------------------------

/**
 * The value of game score.
 **/
@property (readonly,nonatomic) int score;

/**
 * The cars that are involved with card mactching in last user flip.
 **/
@property (nonatomic) NSMutableArray *cardsInlastOperation;

/**
 * The value of points earned in last card matching.
 **/
@property (nonatomic) int pointsEarnInLastOperation;

///---------------------------------------------------------------------------------------
/// @name Initializing a CardMatchingGame
///---------------------------------------------------------------------------------------

/**
 * Initializes and returns a newly allocated CardMatchingGame object with a Deck and number of card matching rule.
 * @param deck Deck object that provides cards for this game.
 * @param matchNumber number of card need to be matched in order to get points.
 * @return CardMatchingGame object
 **/
-(id)initWitCardCount:(NSUInteger)count usingDeck:(Deck*) deck withMatchCardNumber:(NSUInteger)matchNumber;

///---------------------------------------------------------------------------------------
/// @name Game Playing Actions
///---------------------------------------------------------------------------------------

/**
 * Perform a card flipping game play.
 * @param index value of card index in the Deck object.
 **/
-(void)flipCardAtIndex:(NSUInteger) index;

/**
 * Get card of the index.
 * @param index value of card index in the Deck object.
 * @return a Card object of the index.
 **/
-(Card*)cardAtIndex:(NSUInteger) index;

/**
 * Reset game status including score and card staus.
 **/
-(void)resetGame;

/**
 * Draw more cards from deck
 * @param number of card to draw
 * @return array of new cards drawed
 **/
-(NSArray*)drawMoreCardWithCardCount:(NSUInteger)cardCount;

/**
 * Get count of cards that is playable
 * @return playable card counts
 **/
-(NSUInteger) playableCardCount;

/**
 * Remove card from card list that can be play
 * @param the card to be removed
 **/
-(void) removeCard:(Card *)card;

/**
 * Return index of current card
 * @param the card to evluated
 * @return index of the card. return -1 if no card found
 **/
-(NSInteger) indexOfCard:(Card *)card;

/**
 * Return list of cards that currently flipped up
 * @return list of card objects.
 **/
-(NSArray*) cardFlipped;
@end
