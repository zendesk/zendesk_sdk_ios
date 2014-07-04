//
//  ZDDispatcherResponse.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface ZDDispatcherResponse : NSObject


@property (nonatomic, strong) NSHTTPURLResponse *response;
@property (nonatomic, strong) NSData *data;


- (instancetype) initWithResponse:(NSHTTPURLResponse*)response andData:(NSData*)data;


@end

