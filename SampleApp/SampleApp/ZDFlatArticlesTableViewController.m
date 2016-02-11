/*
 *
 *  ZDFlatArticlesTableViewController.m
 *  SampleApp
 *
 *  Created by Zendesk on 31/08/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDFlatArticlesTableViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@interface ZDFlatArticlesTableViewController ()
@property (nonatomic, strong)NSArray *flatArticles;

@end

@implementation ZDFlatArticlesTableViewController

- (void) processFlatArticles
{
    if (self.items) {
        NSMutableArray *flatArticles = [[NSMutableArray alloc] init];
        ZDKHelpCenterFlatArticle * comparisonFlatArticle = self.items.firstObject;
        NSMutableArray *flatArticleArray = [[NSMutableArray alloc] init];
        
        NSString *categorySectionString = [NSString stringWithFormat:@"%@, %@", comparisonFlatArticle.category.name, comparisonFlatArticle.section.name];
        
        for (ZDKHelpCenterFlatArticle *flatArticle in self.items) {
            NSString *categorySectionComparisonString = [NSString stringWithFormat:@"%@, %@", flatArticle.category.name, flatArticle.section.name];
            
            if (![categorySectionComparisonString isEqualToString:categorySectionString]) {
                NSArray *sectionFlatArticleArray = [NSArray arrayWithArray:flatArticleArray];
                [flatArticleArray removeAllObjects];
                [flatArticles addObject:sectionFlatArticleArray];
                categorySectionString = categorySectionComparisonString;
            }
            
            [flatArticleArray addObject:flatArticle];
        }
        [flatArticles addObject:flatArticleArray];
        
        self.flatArticles = [NSArray arrayWithArray:flatArticles];
    }
    
}


- (void)viewDidLoad {
    [super viewDidLoad];
    if ( ! self.navigationItem.leftBarButtonItem) {
        
        UIBarButtonItem *cancelButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(dismiss)];
        self.navigationItem.leftBarButtonItem = cancelButton;
    }
    self.title = @"Article List";
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];

}

- (void) dismiss
{
    [self.navigationController dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return (NSInteger)self.flatArticles.count;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    NSString *sectionName;

    NSArray *articleSectionArray = self.flatArticles[(NSUInteger)section];
    ZDKHelpCenterFlatArticle *flatArticle = articleSectionArray.firstObject;
    sectionName = [NSString stringWithFormat:@"%@, %@", flatArticle.category.name, flatArticle.section.name];
    
    return sectionName;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSArray *rows = self.flatArticles[(NSUInteger)section];
    return (NSInteger) rows.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    
    NSArray *sectionFlatArticleArray = self.flatArticles[(NSUInteger)indexPath.section];
    ZDKHelpCenterFlatArticle *flatArticle = sectionFlatArticleArray[(NSUInteger)indexPath.row];
    
    cell.textLabel.text = flatArticle.article.title;
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSArray *sectionFlatArticleArray = self.flatArticles[(NSUInteger)indexPath.section];
    
    ZDKHelpCenterFlatArticle *flatArticle = sectionFlatArticleArray[(NSUInteger)indexPath.row];
    
    ZDKHelpCenterArticle *article = flatArticle.article;
    
    ZDKArticleViewController *articleViewController = [[ZDKArticleViewController alloc] initWithArticle:article];
    
    [self.navigationController pushViewController:articleViewController animated:YES];
    
}

@end
