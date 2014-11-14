//
//  ZDKCommentsResponse.h
//  ZendeskSDK
//
//  Created by Zendesk on 09/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKCommentsResponse : NSObject

@property (nonatomic, readonly) NSArray *commmentsWithUsers;

+ (NSArray *) parseData:(NSDictionary *) dictionary;

@end
