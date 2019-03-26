//
//  UIImage+Extend.h
//  BankCard
//
//  Created by XAYQ-FanXL on 16/7/8.
//  Copyright © 2016年 AN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface UIImage (Extend)

+ (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)sampleBuffer;
+ (UIImage *)getImageStream:(CVImageBufferRef)imageBuffer;
//截取图片
+ (UIImage *)getSubImage:(CGRect)rect inImage:(UIImage*)image;
 // 始终绘制图片原始状态，不使用Tint Color。
-(UIImage *)originalImage;
//使图片旋转上左下右
+ (UIImage *)image:(UIImage *)image rotation:(UIImageOrientation)orientation;

-(UIImage *)scaleImagetoScale:(CGFloat )scale;
//添加水印 waterImg：水印图片  rect:水印位置
+(UIImage *)addWaterImage:(UIImage *)waterImg toImage:(UIImage *)img AndRect:(CGRect)rect;

+ (CVPixelBufferRef) pixelBufferFromCGImage: (CGImageRef) image;

@end
