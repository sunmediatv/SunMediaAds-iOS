//
//  ViewController.m
//  SunMediaAds
//
//  Created by CISDK on 12/03/2020.
//  Copyright © 2020 SunMediaAds. All rights reserved.
//

#import "ViewController.h"
#import <SunMediaAds/SunMediaAds.h>

@interface ViewController () <LMLDelegate>
@property (nonatomic,strong)IBOutlet UIButton *testButton;
@property (nonatomic,strong)IBOutlet UIButton *showBannerButton;
@property (nonatomic,strong)IBOutlet UIButton *showInterButton;
@property (nonatomic,strong)IBOutlet UIButton *showRewardedButton;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [SunMediaAds initWithAppHash:@"YOUR_APP_HASH" delegate:self viewController:self];
}

-(IBAction)showTest:(id)sender{
    [SunMediaAds testMediationAds:self appHash:@"YOUR_APP_HASH"];
}
-(IBAction)showBanner:(id)sender{
    [SunMediaAds showBannerAdWithDelegate:sender adLocation:@"demo" bannerSettings:LMLBannerSettings_SMART_BOTTOM viewController:self];
}
-(IBAction)showInterstitial:(id)sender{
    [SunMediaAds showInterstitialAdWithDelegate:self adLocation:@"demo" viewController:self];
}
-(IBAction)showRewardedVideo:(id)sender{
    [SunMediaAds showRewardedVideoAdWithDelegate:self adLocation:@"demo" viewController:self];
}


- (void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type zone:(NSString *)zoneId
{
    switch (type)
    {
        case LMLBannerFormat:
            [self.showBannerButton setHidden:NO];
            break;
        case LMLInterstitialFormat:
            [self.showInterButton setHidden:NO];
            break;
        case LMLRewardedVideoFormat:
            [self.showRewardedButton setHidden:NO];
            break;
        default:
            break;
    }
}
- (void)mediationInitialized:(BOOL)state
{
    NSLog(@"SunMediaAds CONTROLLER %d", state);
}
- (void)advertDidInteract:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
    NSLog(@"INTERACT CONTROLLER SunMediaAdsLOG ");
}

- (void)advertWillPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
    
}

- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
    NSLog(@"DID PRESENT CONTROLLER SunMediaAdsLOG %@",zone);
}

- (void)advertWillDismissScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
    NSLog(@"WILL DISMISS CONTROLLER SunMediaAdsLOG ");
}

- (void)advertDidDismissScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone
{
    NSLog(@"DID DISMISS CONTROLLER SunMediaAdsLOG ");
}

- (void)advertDidClose:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
    NSLog(@"CLOSE CONTROLLER SunMediaAdsLOG ");
}

- (void)advertsRequestFail:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
    NSLog(@"FAIL CONTROLLER SunMediaAdsLOG ");
}
- (void)rewardUser:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId
{
    NSLog(@"REWARD CONTROLLER SunMediaAdsLOG ");
}
@end
