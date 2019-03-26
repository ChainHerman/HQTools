//
//  ObtainViewController.m
//  HQBeauty
//
//  Created by macq on 2019/3/19.
//  Copyright © 2019 HQ. All rights reserved.
//

#import "ObtainViewController.h"
#import <AVFoundation/AVFoundation.h>
@interface ObtainViewController ()<AVCaptureVideoDataOutputSampleBufferDelegate>
@property (nonatomic,strong)AVCaptureSession *session;
//#define LYWS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

@end

@implementation ObtainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"采集";
    self.view.backgroundColor = [UIColor orangeColor];
    [self addbackBtn];
    [self initCamero];
}
-(void)addbackBtn
{
    self.navigationItem.leftBarButtonItem  = [[UIBarButtonItem alloc]initWithTitle:@"back" style:UIBarButtonItemStyleDone target:self action:@selector(backhome)];
}
-(void)backhome
{
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];
}
-(void)initCamero
{
    dispatch_queue_t  queue = dispatch_queue_create("myqueue", NULL);

    NSError * er = nil;

    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    AVCaptureDeviceInput *input = [[AVCaptureDeviceInput alloc] initWithDevice:device error:&er];
     _session = [[AVCaptureSession alloc]init];
//    [captureSession setSessionPreset:AVCaptureSessionPresetPhoto];
    LYWS(weakSelf)
    dispatch_async(queue, ^{
        weakSelf.session.sessionPreset = AVCaptureSessionPresetPhoto;
    });
    
    self.session.sessionPreset = AVCaptureSessionPresetPhoto;
    if (er) {
        NSLog(@"发生错误：%@",er);
    }
    if ([self.session canAddInput:input]) {
        [self.session addInput:input];
    }
    AVCaptureVideoPreviewLayer *previewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:self.session];
    previewLayer.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    [self.view.layer insertSublayer:previewLayer atIndex:0];
    AVCaptureVideoDataOutput * videodataputput = [[AVCaptureVideoDataOutput alloc]init];
    [self.session addOutput:videodataputput];
//
    [videodataputput setSampleBufferDelegate:self queue:queue];
    videodataputput.videoSettings = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:kCVPixelFormatType_32BGRA] forKey:(id)kCVPixelBufferPixelFormatTypeKey];
    videodataputput.minFrameDuration = CMTimeMake(1, 15);
    [self.session startRunning];
}
- (void)dealloc
{
    [self.session stopRunning];
}

- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;
{
    
}
- (void)captureOutput:(AVCaptureOutput *)output didDropSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection API_AVAILABLE(ios(6.0));
{
    
}
@end
