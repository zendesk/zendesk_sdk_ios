//
//  RequestListTableViewController.m
//  CoreSDKSample
//
//  Created by Zendesk on 09/07/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "RequestListTableViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation RequestListTableViewController


- (void) viewDidLoad
{
    [super viewDidLoad];

    self.title = @"Request list";
    self.view.backgroundColor = [UIColor colorWithWhite:0.94f alpha:1.0f];

    if ([ZDKUIUtil isSameVersion:@(7)]) {
        self.automaticallyAdjustsScrollViewInsets = NO;
    }

    _requestList = [ZDKRequests newRequestListWith:self andSelector:@selector(requestListUpdated)];

    _table = [[UITableView alloc] initWithFrame:CGRectZero style:(UITableViewStyleGrouped)];
    _table.tableFooterView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 0.0f, 0.01f)];
    _table.dataSource = self;
    _table.delegate = self;
    [self.contentView addSubview:_table];
}


- (void) viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On layout setup the request list frame as desired, using 'tableHeight' to get the table height
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    float tableHeight = self.contentView.frame.size.height;

    _table.frame = CGRectMake(0, 0, self.contentView.frame.size.width, tableHeight);
    _requestList.frame = CGRectMake(0, 0, self.contentView.frame.size.width, [_requestList tableHeight]);
}


- (void) requestListUpdated
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On receiving a notification the table has been updated, use the new height to arrange your UI
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    _requestList.frame = CGRectMake(0, 0, self.view.frame.size.width, [_requestList tableHeight]);

    [_table reloadRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:0 inSection:0]]
                  withRowAnimation:(UITableViewRowAnimationAutomatic)];
}


- (void) dealloc
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remember to remove this class as a notification observer on dealloc
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [_requestList unregisterForEvents:self];
}


#pragma mark tableview datasource


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellId = @"RequestList";
    UITableViewCell *cell = (UITableViewCell*)[tableView dequeueReusableCellWithIdentifier:cellId];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:(UITableViewCellStyleDefault) reuseIdentifier:cellId];
        if ([ZDKUIUtil isSameVersion:@(7)]) {
            cell.separatorInset = UIEdgeInsetsZero;
        }
    }
    [_requestList removeFromSuperview];
    [cell.contentView addSubview:_requestList];
    return cell;
}


#pragma mark tableview delegate


- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return [_requestList tableHeight];
}


- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 25;
}


- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    if (!_header) {

        _header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 25)];
        _header.backgroundColor = [UIColor colorWithWhite:0.97f alpha:1.0f];
        [self.view addSubview:_header];

        float borderHeight = [UIScreen mainScreen].scale == 1.0 ? 1 : 0.5;

        UIView *topBorder = [[UIView alloc] initWithFrame:CGRectMake(0, 0, _header.frame.size.width, borderHeight)];
        topBorder.backgroundColor = [UIColor colorWithWhite:0.88f alpha:1.0f];
        topBorder.autoresizingMask = UIViewAutoresizingFlexibleWidth;
        [_header addSubview:topBorder];

        UILabel *headerLabel = [[UILabel alloc] initWithFrame:CGRectMake(25.0f, 0, _header.frame.size.width, _header.frame.size.height)];
        headerLabel.backgroundColor = [UIColor clearColor];
        headerLabel.autoresizingMask = UIViewAutoresizingFlexibleWidth;
        headerLabel.text = @"YOUR REQUESTS";
        headerLabel.textColor = [UIColor colorWithWhite:0.33f alpha:1.0f];
        headerLabel.font = [UIFont systemFontOfSize:11];
        [_header addSubview:headerLabel];

    }

    return _header;
}



@end
