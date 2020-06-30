//
//  LabCaveMediationDelegate.h
//  LabCaveMediationLayer
//
//  Created by LabCaveGames on 24/2/17.
//  Copyright © 2017 Lab Cave Apps S.L. All rights reserved.
//

#import "LMLBannerView.h"
#import "LMLBannerSettings.h"

#define LML_REWARDED_VIDEO @"rewardedvideo"
#define LML_INTERSTITIAL @"interstitial"
#define LML_BANNER @"banner"
/**
 *  Advert Type
 */
typedef NS_ENUM(NSUInteger, LMLType) {
    LMLUnknownFormat = 99,
    /**
     *  Banner
     */
    LMLBannerFormat = 0,

    /**
     *  Interstitial
     */
    LMLInterstitialFormat,

    /**
     *  Video
     */
    LMLVideoFormat,

    /**
     *  RewardedVideo
     */
    LMLRewardedVideoFormat
};
/**
 * LabCaveGamesDelegate
 */
@protocol LMLDelegate

@optional

/**
 *  Mediation Initialized
 *
  */
- (void)mediationInitialized:(BOOL)state;

/**
 *  Advert Loaded
 *
 */
- (void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type zone:(NSString *)zoneId;

- (void)advertLoaded:(NSString *)provider view:(LMLBannerView *)advert type:(LMLType)type adLocation:(NSString *)adLocation;
/**
 *  Advert Did Present Screen
 *
 */
- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type zone:(NSString *)zone;

- (void)advertDidPresentScreen:(NSString *)provider type:(LMLType)type adLocation:(NSString *)adLocation;

/**
 *  Advert Did Interact
 *
 */
- (void)advertDidInteract:(NSString *)provider type:(LMLType)type zone:(NSString *)zone;

- (void)advertDidInteract:(NSString *)provider type:(LMLType)type adLocation:(NSString *)adLocation;

/**
 * Advert Web View Did Close
 */
- (void)advertDidClose:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;

- (void)advertDidClose:(NSString *)provider type:(LMLType)type adLocation:(NSString *)adLocation reward:(BOOL)reward;

/**
 * Advert Request Fail
 */
- (void)advertsRequestFail:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;

- (void)advertsRequestFail:(NSString *)provider type:(LMLType)type adLocation:(NSString *)adLocation;

/**
 * Reward user
 */
- (void)rewardUser:(NSString *)provider type:(LMLType)type zone:(NSString *)zoneId;
- (void)rewardUser:(NSString *)provider type:(LMLType)type adLocation:(NSString *)adLocation;
@end
