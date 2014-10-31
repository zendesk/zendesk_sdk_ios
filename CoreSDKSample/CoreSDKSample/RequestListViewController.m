//
//  RequestListViewController.m
//  CoreSDKSample
//
//  Created by Zendesk on 09/07/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "RequestListViewController.h"


@implementation RequestListViewController


- (void) viewDidLoad
{
    [super viewDidLoad];

    self.title = @"Request list";
    self.contentView.backgroundColor = [UIColor colorWithWhite:0.94f alpha:1.0f];

    // request list header
    _header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.contentView.frame.size.width, 25)];
    _header.backgroundColor = [UIColor colorWithWhite:0.97f alpha:1.0f];
    [self.contentView addSubview:_header];

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

    UIView *lowerBorder = [[UIView alloc] initWithFrame:CGRectMake(0, _header.frame.size.height - borderHeight, _header.frame.size.width, borderHeight)];
    lowerBorder.backgroundColor = [UIColor colorWithWhite:0.88f alpha:1.0f];
    lowerBorder.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [_header addSubview:lowerBorder];

    // wrap the request list view into a scrollview.
    _requestList = [ZDKRequests newRequestListWith:self andSelector:@selector(requestListUpdated)];
    _requestListContainer = [[UIScrollView alloc] initWithFrame:CGRectZero];
    _requestListContainer.backgroundColor = [UIColor whiteColor];
    [self.requestListContainer addSubview:_requestList];

    [self.contentView addSubview:_requestListContainer];
}


- (void) viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];

    [self layoutContent];

}


- (void) layoutContent
{
    [super layoutContent];
    
    _header.frame = CGRectMake(0, 0, self.contentView.frame.size.width, _header.frame.size.height);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On layout setup the request list frame as desired, using 'tableHeight' to get the table height
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    float containerOriginY = CGRectGetMaxY(_header.frame);
    float containerHeight = self.contentView.frame.size.height - _header.frame.size.height;
    
    _requestList.frame= CGRectMake(0, 0, self.contentView.frame.size.width, [_requestList tableHeight]);
    
    _requestListContainer.frame = CGRectMake(0, containerOriginY , self.contentView.frame.size.width, containerHeight);
    _requestListContainer.contentSize = CGSizeMake(self.contentView.frame.size.width, [_requestList tableHeight]);
}


- (void) requestListUpdated
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On receiving a notification the table has been updated, use the new height to arrange your UI
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [UIView animateWithDuration:0.25f animations:^{
        _requestList.frame= CGRectMake(0, CGRectGetMaxY(_header.frame), self.contentView.frame.size.width, [_requestList tableHeight]);
    }];

    [self.view setNeedsLayout];
}


- (void) dealloc
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remember to remove this class as a notification observer on dealloc
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [_requestList unregisterForEvents:self];
}


@end

