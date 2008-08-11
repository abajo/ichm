//
//  CHMTableOfContent.h
//  ichm
//
//  Created by Robin Lu on 7/18/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class LinkItem;

@interface CHMTableOfContent : NSObject {
	LinkItem *rootItems;
	
	NSMutableArray *itemStack;
	LinkItem *curItem;
}

- (id)initWithData:(NSData *)data encodingName:(NSString*)encodingName;
- (LinkItem *)itemForPath:(NSString*)path withStack:(NSMutableArray*)stack;
- (int)rootChildrenCount;
@end

@interface CHMSearchResult : CHMTableOfContent
{
	CHMTableOfContent* tableOfContent;
}

- (id)initwithTOC:(CHMTableOfContent*)toc;
- (void)addPath:(NSString*)path Score:(float)score;
- (void)sort;
@end

@interface LinkItem	: NSObject
{
	NSString *_name;
	NSString *_path;
	NSMutableArray *_children;
}

- (id)initWithName:(NSString *)name Path:(NSString *)path;
- (int)numberOfChildren;
- (LinkItem *)childAtIndex:(int)n;
- (NSString *)name;
- (NSString *)path;
- (void)setName:(NSString *)name;
- (void)setPath:(NSString *)path;
- (void)appendChild:(LinkItem *)item;
- (LinkItem*)find_by_path:(NSString *)path withStack:(NSMutableArray*)stack;
@end

@interface ScoredLinkItem : LinkItem
{
	float relScore;
}

@property (readwrite, assign) float relScore;

- (id)initWithName:(NSString *)name Path:(NSString *)path Score:(float)score;
- (void)sort;
@end
