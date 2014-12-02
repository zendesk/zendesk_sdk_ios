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


@protocol ZDKDispatcherDelegate <NSObject>


#pragma mark config


/**
 * Checks if config is valid for auth requirements
 *
 * @param authRequired bool indicating if auth is a requirement for this request
 *
 * @return YES is config is sufficient to perform a request
 */
- (BOOL) validAccount:(BOOL)authRequired;


/**
 * Helper for generating validation errors, override to implement.
 *
 * @return error as appropriate for the current config
 */
- (NSError*) accountError;


@optional


#pragma mark login


/**
 * Check if login is currently required or we already have validated credentials.
 *
 * @return YES is login is required
 */
- (BOOL) needToLogin;


/**
 * Generate a login request, this should be a self contained request and not result in a form.
 *
 * @return the login request to be sent
 */
- (NSMutableURLRequest*) createLoginRequest;


/**
 * Override to handle the responses to the login request.
 *
 * @param responseData the login response data
 *
 * @return YES if login was successful
 */
- (BOOL) handleLoginResponse:(ZDKDispatcherResponse*)responseData;


#pragma mark auth


/**
 * Add auth info to the request
 *
 * @param request the request to be updated
 */
- (void) addAuthToRequest:(NSMutableURLRequest*)request;



/**
 * Inform the delegate that the token is invalid and should be discarded.
 */
- (void) invalidateToken;


@end

