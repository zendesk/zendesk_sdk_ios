/*
 *
 *  ZDKDispatcherDelegate.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 09/06/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>
#import "ZDKDispatcherResponse.h"

/**
 *  Delegate methods for ZDKDispatcher.
 *
 *  @since 0.9.3.1
 */
@protocol ZDKDispatcherDelegate <NSObject>


#pragma mark config


/**
 *  Checks if config is valid for auth requirements
 *
 *  @since 0.9.3.1
 *
 *  @param authRequired bool indicating if auth is a requirement for this request
 *
 *  @return YES is config is sufficient to perform a request
 */
- (BOOL) validAccount:(BOOL)authRequired;


/**
 *  Helper for generating validation errors, override to implement.
 *
 *  @since 0.9.3.1
 *
 *  @return error as appropriate for the current config
 */
- (NSError*) accountError;


@optional


#pragma mark login


/**
 *  Check if login is currently required or we already have validated credentials.
 *
 *  @since 0.9.3.1
 *
 *  @return YES is login is required
 */
- (BOOL) needToLogin;


/**
 *  Generate a login request, this should be a self contained request and not result in a form.
 *
 *  @since 0.9.3.1
 *
 *  @return the login request to be sent
 */
- (NSMutableURLRequest*) createLoginRequest;


/**
 *  Override to handle the responses to the login request.
 *
 *  @since 0.9.3.1
 *
 *  @param responseData the login response data
 *
 *  @return YES if login was successful
 */
- (BOOL) handleLoginResponse:(ZDKDispatcherResponse*)responseData;


#pragma mark auth


/**
 *  Add auth info to the request
 *
 *  @since 0.9.3.1
 *
 *  @param request the request to be updated
 */
- (void) addAuthToRequest:(NSMutableURLRequest*)request;



/**
 *  Inform the delegate that the token is invalid and should be discarded.
 *
 *  @since 0.9.3.1
 */
- (void) invalidateToken;


/**
 *  Inform the delegate that the user identity is invalid and should be discarded.
 *
 *  @since 0.9.3.1
 */
- (void) invalidateIdentity;

@end

