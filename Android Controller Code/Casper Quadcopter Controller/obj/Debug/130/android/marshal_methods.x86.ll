; ModuleID = 'obj\Debug\130\android\marshal_methods.x86.ll'
source_filename = "obj\Debug\130\android\marshal_methods.x86.ll"
target datalayout = "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-unknown-linux-android"


%struct.MonoImage = type opaque

%struct.MonoClass = type opaque

%struct.MarshalMethodsManagedClass = type {
	i32,; uint32_t token
	%struct.MonoClass*; MonoClass* klass
}

%struct.MarshalMethodName = type {
	i64,; uint64_t id
	i8*; char* name
}

%class._JNIEnv = type opaque

%class._jobject = type {
	i8; uint8_t b
}

%class._jclass = type {
	i8; uint8_t b
}

%class._jstring = type {
	i8; uint8_t b
}

%class._jthrowable = type {
	i8; uint8_t b
}

%class._jarray = type {
	i8; uint8_t b
}

%class._jobjectArray = type {
	i8; uint8_t b
}

%class._jbooleanArray = type {
	i8; uint8_t b
}

%class._jbyteArray = type {
	i8; uint8_t b
}

%class._jcharArray = type {
	i8; uint8_t b
}

%class._jshortArray = type {
	i8; uint8_t b
}

%class._jintArray = type {
	i8; uint8_t b
}

%class._jlongArray = type {
	i8; uint8_t b
}

%class._jfloatArray = type {
	i8; uint8_t b
}

%class._jdoubleArray = type {
	i8; uint8_t b
}

; assembly_image_cache
@assembly_image_cache = local_unnamed_addr global [0 x %struct.MonoImage*] zeroinitializer, align 4
; Each entry maps hash of an assembly name to an index into the `assembly_image_cache` array
@assembly_image_cache_hashes = local_unnamed_addr constant [110 x i32] [
	i32 32687329, ; 0: Xamarin.AndroidX.Lifecycle.Runtime => 0x1f2c4e1 => 32
	i32 34715100, ; 1: Xamarin.Google.Guava.ListenableFuture.dll => 0x211b5dc => 50
	i32 101534019, ; 2: Xamarin.AndroidX.SlidingPaneLayout => 0x60d4943 => 41
	i32 120558881, ; 3: Xamarin.AndroidX.SlidingPaneLayout.dll => 0x72f9521 => 41
	i32 165246403, ; 4: Xamarin.AndroidX.Collection.dll => 0x9d975c3 => 19
	i32 182336117, ; 5: Xamarin.AndroidX.SwipeRefreshLayout.dll => 0xade3a75 => 42
	i32 209399409, ; 6: Xamarin.AndroidX.Browser.dll => 0xc7b2e71 => 17
	i32 230216969, ; 7: Xamarin.AndroidX.Legacy.Support.Core.Utils.dll => 0xdb8d509 => 29
	i32 280482487, ; 8: Xamarin.AndroidX.Interpolator => 0x10b7d2b7 => 27
	i32 318968648, ; 9: Xamarin.AndroidX.Activity.dll => 0x13031348 => 10
	i32 321597661, ; 10: System.Numerics => 0x132b30dd => 6
	i32 342366114, ; 11: Xamarin.AndroidX.Lifecycle.Common => 0x146817a2 => 30
	i32 442521989, ; 12: Xamarin.Essentials => 0x1a605985 => 48
	i32 450948140, ; 13: Xamarin.AndroidX.Fragment.dll => 0x1ae0ec2c => 26
	i32 465846621, ; 14: mscorlib => 0x1bc4415d => 3
	i32 469710990, ; 15: System.dll => 0x1bff388e => 5
	i32 476646585, ; 16: Xamarin.AndroidX.Interpolator.dll => 0x1c690cb9 => 27
	i32 486930444, ; 17: Xamarin.AndroidX.LocalBroadcastManager.dll => 0x1d05f80c => 36
	i32 526760484, ; 18: Casper Quadcopter Controller => 0x1f65ba24 => 0
	i32 627609679, ; 19: Xamarin.AndroidX.CustomView => 0x2568904f => 23
	i32 663517072, ; 20: Xamarin.AndroidX.VersionedParcelable => 0x278c7790 => 46
	i32 666292255, ; 21: Xamarin.AndroidX.Arch.Core.Common.dll => 0x27b6d01f => 14
	i32 809851609, ; 22: System.Drawing.Common.dll => 0x30455ad9 => 52
	i32 843511501, ; 23: Xamarin.AndroidX.Print => 0x3246f6cd => 38
	i32 928116545, ; 24: Xamarin.Google.Guava.ListenableFuture => 0x3751ef41 => 50
	i32 967690846, ; 25: Xamarin.AndroidX.Lifecycle.Common.dll => 0x39adca5e => 30
	i32 1012816738, ; 26: Xamarin.AndroidX.SavedState.dll => 0x3c5e5b62 => 40
	i32 1035644815, ; 27: Xamarin.AndroidX.AppCompat => 0x3dbaaf8f => 13
	i32 1052210849, ; 28: Xamarin.AndroidX.Lifecycle.ViewModel.dll => 0x3eb776a1 => 33
	i32 1098259244, ; 29: System => 0x41761b2c => 5
	i32 1175144683, ; 30: Xamarin.AndroidX.VectorDrawable.Animated => 0x460b48eb => 44
	i32 1204270330, ; 31: Xamarin.AndroidX.Arch.Core.Common => 0x47c7b4fa => 14
	i32 1267360935, ; 32: Xamarin.AndroidX.VectorDrawable => 0x4b8a64a7 => 45
	i32 1293217323, ; 33: Xamarin.AndroidX.DrawerLayout.dll => 0x4d14ee2b => 25
	i32 1376866003, ; 34: Xamarin.AndroidX.SavedState => 0x52114ed3 => 40
	i32 1406073936, ; 35: Xamarin.AndroidX.CoordinatorLayout => 0x53cefc50 => 20
	i32 1469204771, ; 36: Xamarin.AndroidX.AppCompat.AppCompatResources => 0x57924923 => 12
	i32 1582372066, ; 37: Xamarin.AndroidX.DocumentFile.dll => 0x5e5114e2 => 24
	i32 1622152042, ; 38: Xamarin.AndroidX.Loader.dll => 0x60b0136a => 35
	i32 1636350590, ; 39: Xamarin.AndroidX.CursorAdapter => 0x6188ba7e => 22
	i32 1639515021, ; 40: System.Net.Http.dll => 0x61b9038d => 51
	i32 1657153582, ; 41: System.Runtime => 0x62c6282e => 8
	i32 1658251792, ; 42: Xamarin.Google.Android.Material.dll => 0x62d6ea10 => 49
	i32 1729485958, ; 43: Xamarin.AndroidX.CardView.dll => 0x6715dc86 => 18
	i32 1766324549, ; 44: Xamarin.AndroidX.SwipeRefreshLayout => 0x6947f945 => 42
	i32 1776026572, ; 45: System.Core.dll => 0x69dc03cc => 4
	i32 1788241197, ; 46: Xamarin.AndroidX.Fragment => 0x6a96652d => 26
	i32 1808609942, ; 47: Xamarin.AndroidX.Loader => 0x6bcd3296 => 35
	i32 1813201214, ; 48: Xamarin.Google.Android.Material => 0x6c13413e => 49
	i32 1867746548, ; 49: Xamarin.Essentials.dll => 0x6f538cf4 => 48
	i32 1885316902, ; 50: Xamarin.AndroidX.Arch.Core.Runtime.dll => 0x705fa726 => 15
	i32 1919157823, ; 51: Xamarin.AndroidX.MultiDex.dll => 0x7264063f => 37
	i32 2019465201, ; 52: Xamarin.AndroidX.Lifecycle.ViewModel => 0x785e97f1 => 33
	i32 2055257422, ; 53: Xamarin.AndroidX.Lifecycle.LiveData.Core.dll => 0x7a80bd4e => 31
	i32 2079903147, ; 54: System.Runtime.dll => 0x7bf8cdab => 8
	i32 2090596640, ; 55: System.Numerics.Vectors => 0x7c9bf920 => 7
	i32 2097448633, ; 56: Xamarin.AndroidX.Legacy.Support.Core.UI => 0x7d0486b9 => 28
	i32 2201231467, ; 57: System.Net.Http => 0x8334206b => 51
	i32 2217644978, ; 58: Xamarin.AndroidX.VectorDrawable.Animated.dll => 0x842e93b2 => 44
	i32 2244775296, ; 59: Xamarin.AndroidX.LocalBroadcastManager => 0x85cc8d80 => 36
	i32 2256548716, ; 60: Xamarin.AndroidX.MultiDex => 0x8680336c => 37
	i32 2279755925, ; 61: Xamarin.AndroidX.RecyclerView.dll => 0x87e25095 => 39
	i32 2315684594, ; 62: Xamarin.AndroidX.Annotation.dll => 0x8a068af2 => 11
	i32 2475788418, ; 63: Java.Interop.dll => 0x93918882 => 1
	i32 2505896520, ; 64: Xamarin.AndroidX.Lifecycle.Runtime.dll => 0x955cf248 => 32
	i32 2581819634, ; 65: Xamarin.AndroidX.VectorDrawable.dll => 0x99e370f2 => 45
	i32 2620871830, ; 66: Xamarin.AndroidX.CursorAdapter.dll => 0x9c375496 => 22
	i32 2732626843, ; 67: Xamarin.AndroidX.Activity => 0xa2e0939b => 10
	i32 2737747696, ; 68: Xamarin.AndroidX.AppCompat.AppCompatResources.dll => 0xa32eb6f0 => 12
	i32 2778768386, ; 69: Xamarin.AndroidX.ViewPager.dll => 0xa5a0a402 => 47
	i32 2810250172, ; 70: Xamarin.AndroidX.CoordinatorLayout.dll => 0xa78103bc => 20
	i32 2819470561, ; 71: System.Xml.dll => 0xa80db4e1 => 9
	i32 2853208004, ; 72: Xamarin.AndroidX.ViewPager => 0xaa107fc4 => 47
	i32 2855708567, ; 73: Xamarin.AndroidX.Transition => 0xaa36a797 => 43
	i32 2903344695, ; 74: System.ComponentModel.Composition => 0xad0d8637 => 54
	i32 2905242038, ; 75: mscorlib.dll => 0xad2a79b6 => 3
	i32 2919462931, ; 76: System.Numerics.Vectors.dll => 0xae037813 => 7
	i32 2978675010, ; 77: Xamarin.AndroidX.DrawerLayout => 0xb18af942 => 25
	i32 3024354802, ; 78: Xamarin.AndroidX.Legacy.Support.Core.Utils => 0xb443fdf2 => 29
	i32 3211777861, ; 79: Xamarin.AndroidX.DocumentFile => 0xbf6fd745 => 24
	i32 3247949154, ; 80: Mono.Security => 0xc197c562 => 53
	i32 3258312781, ; 81: Xamarin.AndroidX.CardView => 0xc235e84d => 18
	i32 3267021929, ; 82: Xamarin.AndroidX.AsyncLayoutInflater => 0xc2bacc69 => 16
	i32 3317135071, ; 83: Xamarin.AndroidX.CustomView.dll => 0xc5b776df => 23
	i32 3340431453, ; 84: Xamarin.AndroidX.Arch.Core.Runtime => 0xc71af05d => 15
	i32 3353484488, ; 85: Xamarin.AndroidX.Legacy.Support.Core.UI.dll => 0xc7e21cc8 => 28
	i32 3362522851, ; 86: Xamarin.AndroidX.Core => 0xc86c06e3 => 21
	i32 3366347497, ; 87: Java.Interop => 0xc8a662e9 => 1
	i32 3374999561, ; 88: Xamarin.AndroidX.RecyclerView => 0xc92a6809 => 39
	i32 3429136800, ; 89: System.Xml => 0xcc6479a0 => 9
	i32 3476120550, ; 90: Mono.Android => 0xcf3163e6 => 2
	i32 3501239056, ; 91: Xamarin.AndroidX.AsyncLayoutInflater.dll => 0xd0b0ab10 => 16
	i32 3508111545, ; 92: Casper Quadcopter Controller.dll => 0xd11988b9 => 0
	i32 3567349600, ; 93: System.ComponentModel.Composition.dll => 0xd4a16f60 => 54
	i32 3627220390, ; 94: Xamarin.AndroidX.Print.dll => 0xd832fda6 => 38
	i32 3641597786, ; 95: Xamarin.AndroidX.Lifecycle.LiveData.Core => 0xd90e5f5a => 31
	i32 3672681054, ; 96: Mono.Android.dll => 0xdae8aa5e => 2
	i32 3682565725, ; 97: Xamarin.AndroidX.Browser => 0xdb7f7e5d => 17
	i32 3689375977, ; 98: System.Drawing.Common => 0xdbe768e9 => 52
	i32 3718780102, ; 99: Xamarin.AndroidX.Annotation => 0xdda814c6 => 11
	i32 3786282454, ; 100: Xamarin.AndroidX.Collection => 0xe1ae15d6 => 19
	i32 3829621856, ; 101: System.Numerics.dll => 0xe4436460 => 6
	i32 3885922214, ; 102: Xamarin.AndroidX.Transition.dll => 0xe79e77a6 => 43
	i32 3896760992, ; 103: Xamarin.AndroidX.Core.dll => 0xe843daa0 => 21
	i32 3921031405, ; 104: Xamarin.AndroidX.VersionedParcelable.dll => 0xe9b630ed => 46
	i32 3955647286, ; 105: Xamarin.AndroidX.AppCompat.dll => 0xebc66336 => 13
	i32 4105002889, ; 106: Mono.Security.dll => 0xf4ad5f89 => 53
	i32 4151237749, ; 107: System.Core => 0xf76edc75 => 4
	i32 4182413190, ; 108: Xamarin.AndroidX.Lifecycle.ViewModelSavedState.dll => 0xf94a8f86 => 34
	i32 4292120959 ; 109: Xamarin.AndroidX.Lifecycle.ViewModelSavedState => 0xffd4917f => 34
], align 4
@assembly_image_cache_indices = local_unnamed_addr constant [110 x i32] [
	i32 32, i32 50, i32 41, i32 41, i32 19, i32 42, i32 17, i32 29, ; 0..7
	i32 27, i32 10, i32 6, i32 30, i32 48, i32 26, i32 3, i32 5, ; 8..15
	i32 27, i32 36, i32 0, i32 23, i32 46, i32 14, i32 52, i32 38, ; 16..23
	i32 50, i32 30, i32 40, i32 13, i32 33, i32 5, i32 44, i32 14, ; 24..31
	i32 45, i32 25, i32 40, i32 20, i32 12, i32 24, i32 35, i32 22, ; 32..39
	i32 51, i32 8, i32 49, i32 18, i32 42, i32 4, i32 26, i32 35, ; 40..47
	i32 49, i32 48, i32 15, i32 37, i32 33, i32 31, i32 8, i32 7, ; 48..55
	i32 28, i32 51, i32 44, i32 36, i32 37, i32 39, i32 11, i32 1, ; 56..63
	i32 32, i32 45, i32 22, i32 10, i32 12, i32 47, i32 20, i32 9, ; 64..71
	i32 47, i32 43, i32 54, i32 3, i32 7, i32 25, i32 29, i32 24, ; 72..79
	i32 53, i32 18, i32 16, i32 23, i32 15, i32 28, i32 21, i32 1, ; 80..87
	i32 39, i32 9, i32 2, i32 16, i32 0, i32 54, i32 38, i32 31, ; 88..95
	i32 2, i32 17, i32 52, i32 11, i32 19, i32 6, i32 43, i32 21, ; 96..103
	i32 46, i32 13, i32 53, i32 4, i32 34, i32 34 ; 104..109
], align 4

@marshal_methods_number_of_classes = local_unnamed_addr constant i32 0, align 4

; marshal_methods_class_cache
@marshal_methods_class_cache = global [0 x %struct.MarshalMethodsManagedClass] [
], align 4; end of 'marshal_methods_class_cache' array


@get_function_pointer = internal unnamed_addr global void (i32, i32, i32, i8**)* null, align 4

; Function attributes: "frame-pointer"="none" "min-legal-vector-width"="0" mustprogress nofree norecurse nosync "no-trapping-math"="true" nounwind sspstrong "stack-protector-buffer-size"="8" "stackrealign" "target-cpu"="i686" "target-features"="+cx8,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "tune-cpu"="generic" uwtable willreturn writeonly
define void @xamarin_app_init (void (i32, i32, i32, i8**)* %fn) local_unnamed_addr #0
{
	store void (i32, i32, i32, i8**)* %fn, void (i32, i32, i32, i8**)** @get_function_pointer, align 4
	ret void
}

; Names of classes in which marshal methods reside
@mm_class_names = local_unnamed_addr constant [0 x i8*] zeroinitializer, align 4
@__MarshalMethodName_name.0 = internal constant [1 x i8] c"\00", align 1

; mm_method_names
@mm_method_names = local_unnamed_addr constant [1 x %struct.MarshalMethodName] [
	; 0
	%struct.MarshalMethodName {
		i64 0, ; id 0x0; name: 
		i8* getelementptr inbounds ([1 x i8], [1 x i8]* @__MarshalMethodName_name.0, i32 0, i32 0); name
	}
], align 8; end of 'mm_method_names' array


attributes #0 = { "min-legal-vector-width"="0" mustprogress nofree norecurse nosync "no-trapping-math"="true" nounwind sspstrong "stack-protector-buffer-size"="8" uwtable willreturn writeonly "frame-pointer"="none" "target-cpu"="i686" "target-features"="+cx8,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "tune-cpu"="generic" "stackrealign" }
attributes #1 = { "min-legal-vector-width"="0" mustprogress "no-trapping-math"="true" nounwind sspstrong "stack-protector-buffer-size"="8" uwtable "frame-pointer"="none" "target-cpu"="i686" "target-features"="+cx8,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "tune-cpu"="generic" "stackrealign" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}
!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 1, !"NumRegisterParameters", i32 0}
!3 = !{!"Xamarin.Android remotes/origin/d17-5 @ a8a26c7b003e2524cc98acb2c2ffc2ddea0f6692"}
!llvm.linker.options = !{}
