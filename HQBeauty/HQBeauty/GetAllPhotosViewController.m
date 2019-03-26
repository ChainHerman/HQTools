//
//  GetAllPhotosViewController.m
//  HQBeauty
//
//  Created by macq on 2019/3/20.
//  Copyright © 2019 HQ. All rights reserved.
//

#import "GetAllPhotosViewController.h"
#import <Photos/Photos.h>
@interface GetAllPhotosViewController ()

@end

@implementation GetAllPhotosViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    PHFetchOptions *option = [[PHFetchOptions alloc]init];
    option.includeHiddenAssets = YES;
    option.includeAllBurstAssets = YES;

    PHFetchResult *result =  [PHAssetCollection fetchTopLevelUserCollectionsWithOptions:option];
    PHAssetCollectionSubtype subType = PHAssetCollectionSubtypeAlbumRegular;
    PHFetchResult *smartAlbumsResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeSmartAlbum subtype:subType options:option];
    
    NSMutableArray *photoGroups = [NSMutableArray array];

    [result enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([obj isKindOfClass:[PHAssetCollection class]]) {
            PHAssetCollection *asset = (PHAssetCollection *)obj;
            PHFetchResult *result = [PHAsset fetchAssetsInAssetCollection:asset options:[PHFetchOptions new]];
            if (result.count > 0) {
                
//                PhotoAssetGroup *g = [PhotoAssetGroup groupWithName:asset.localizedTitle fetchResult:result];
//                [photoGroups addObject:g];
//                NSLog(@"asset.localizedTitle:%@\n",asset.localizedTitle);
//                NSLog(@"result:%@\n",[result objectAtIndex:0]);

            }
        }
        
    }];
    [smartAlbumsResult enumerateObjectsWithOptions:NSEnumerationReverse usingBlock:^(id _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([obj isKindOfClass:[PHAssetCollection class]]) {
            PHAssetCollection *asset = (PHAssetCollection *)obj;
            PHFetchOptions *options = [[PHFetchOptions alloc] init];
            options.sortDescriptors = @[[NSSortDescriptor sortDescriptorWithKey:@"creationDate" ascending:NO]];
            
            PHFetchResult *result = [PHAsset fetchAssetsInAssetCollection:asset options:options];
            if(result.count > 0 && asset.assetCollectionSubtype != PHAssetCollectionSubtypeSmartAlbumVideos) {
                //                    PhotoAssetGroup *g = [PhotoAssetGroup groupWithName:asset.localizedTitle fetchResult:result];
                //                    [photoGroups addObject:g];
                NSLog(@"asset.localizedTitle:%@\n",asset.localizedTitle);
                NSLog(@"result:%@\n",[result objectAtIndex:0]);
            }
        }
    }];
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
