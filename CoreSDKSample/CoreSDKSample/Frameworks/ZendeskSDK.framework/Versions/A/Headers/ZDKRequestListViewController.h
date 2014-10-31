//
//  ZDKRequestListViewController.h
//  ZendeskSDK
//
//  Created by Zendesk on 15/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZendeskSDK/ZDKRequests.h"

@interface ZDKRequestListViewController : ZDKUIViewController

@property (nonatomic, strong) UIScrollView *requestListContainer;
@property (nonatomic, strong) ZDKRequestListTable *requestList;

@end
