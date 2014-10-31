//
//  RequestListTableViewController.h
//  CoreSDKSample
//
//  Created by Zendesk on 09/07/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <ZendeskSDK/ZDKRequests.h>


@interface RequestListTableViewController : ZDKUIViewController <UITableViewDataSource, UITableViewDelegate>


@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) UIView *header;
@property (nonatomic, strong) ZDKRequestListTable *requestList;


@end

