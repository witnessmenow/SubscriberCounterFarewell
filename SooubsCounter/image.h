// This is a horribly inefficient way of drawing this, but meh.. :)
// Converted using the following site: http://www.rinkydinkelectronics.com/t_imageconverter565.php
uint16_t static sooubs[] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0010 (16) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020,   // 0x0020 (32) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0030 (48) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x07E0, 0x0861, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0040 (64) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0041, 0x0061, 0x0061, 0x0020, 0x0800,   // 0x0050 (80) pixels
0x0800, 0x0040, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0881, 0x0020, 0x0041, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,   // 0x0060 (96) pixels
0x07E0, 0x0040, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0040, 0x0020, 0x0020, 0x0041, 0x0041, 0x0041, 0x0061, 0x0041, 0x0040,   // 0x0070 (112) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0080 (128) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0821, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,   // 0x0090 (144) pixels
0x00A2, 0x07E0, 0x07E0, 0x74D1, 0xA617, 0xAE37, 0x8553, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x74B1, 0xA617, 0x9DD6, 0x74B1,   // 0x00A0 (160) pixels
0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,   // 0x00B0 (176) pixels
0x07E0, 0x07E0, 0x0020, 0x0000, 0x0061, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0xFFE0, 0x07E0, 0x08C2, 0x0820, 0x0000, 0x0000,   // 0x00C0 (192) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x07E0, 0x07E0, 0x6C90, 0xBE99, 0xD73C, 0xC6DA, 0x8554, 0x07E0,   // 0x00D0 (208) pixels
0x07E0, 0x07E0, 0xDF5C, 0xF7DF, 0xFFFF, 0xFFBF, 0xFFFF, 0xCEDA, 0x07E0, 0x07E0, 0x6470, 0xE77D, 0xFFFF, 0xFFDF, 0xFFDF, 0xFFBF,   // 0x00E0 (224) pixels
0xB658, 0x07E0, 0x07E0, 0xBE99, 0xC699, 0xA637, 0x07E0, 0x6CD1, 0xC6DA, 0xC6DA, 0x8533, 0x07E0, 0xC6AC, 0xCECA, 0xCEC9, 0xC6A9,   // 0x00F0 (240) pixels
0x6C29, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x6429, 0x9D6A, 0x9549, 0x4BE8, 0xFFE0, 0x744E, 0x07E0, 0x0820, 0x0000, 0x0000,   // 0x0100 (256) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x07E0, 0x07E0, 0xBEDA, 0xF7BF, 0xFFBF, 0xFFDF, 0xFFDF, 0xEFDF, 0x07E0,   // 0x0110 (272) pixels
0x07E0, 0xEF9E, 0xFF9E, 0xF7FF, 0xF7DF, 0xFFDF, 0xFFDF, 0xF7BF, 0x07E0, 0x6470, 0xF79E, 0xFFFF, 0xF7FF, 0xF7FF, 0xFFFF, 0xFFFF,   // 0x0120 (288) pixels
0xEFBE, 0x07E0, 0x84F2, 0xF7FF, 0xFFFF, 0x9E17, 0x07E0, 0xC71B, 0xF7FF, 0xF7FF, 0x07E0, 0xB6AE, 0xFFC0, 0xFFE1, 0xFFE0, 0xFFC0,   // 0x0130 (304) pixels
0xFFE0, 0xBEAB, 0x07E0, 0x07E0, 0xA58A, 0xF7A3, 0xFFC0, 0xFFE0, 0xFFC0, 0xFFE0, 0xFFC0, 0xE784, 0x07E0, 0x07E0, 0x0820, 0x0000,   // 0x0140 (320) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x07E0, 0x07E0, 0xA617, 0xFFDF, 0xFFDF, 0xF7DF, 0xE77D, 0xFFDF, 0xA637, 0x07E0,   // 0x0150 (336) pixels
0xBEBA, 0xFFBF, 0xF7DF, 0xA617, 0x9D75, 0xFFFF, 0xFFDF, 0xE7BE, 0x07E0, 0xDF7D, 0xFFDF, 0xFFFF, 0x9DD6, 0xB617, 0xFFDF, 0xFFFF,   // 0x0160 (352) pixels
0xEF9E, 0x07E0, 0xCEDA, 0xFFDF, 0xFFDF, 0x07E0, 0x07E0, 0xEFBE, 0xFFDF, 0xEF5D, 0x07E0, 0xEFA6, 0xFFC1, 0xFFC1, 0xCEE5, 0xF7C2,   // 0x0170 (368) pixels
0xFFE0, 0xEFA8, 0x07E0, 0xAE47, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xADCD, 0x07E0, 0x1061, 0x0020,   // 0x0180 (384) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0xE79E, 0xFFDF, 0xF7DF, 0x9D54, 0x07E0, 0x07E0, 0x07E0, 0x07E0,   // 0x0190 (400) pixels
0xF7DF, 0xFFBF, 0xE79D, 0x07E0, 0x07E0, 0xF7DE, 0xFFDF, 0xCEDA, 0x07E0, 0xF7DE, 0xFFDF, 0xD6FB, 0x07E0, 0x8CF3, 0xFFFF, 0xFFDF,   // 0x01A0 (416) pixels
0xC699, 0x07E0, 0xF7DF, 0xFFFF, 0xE75D, 0x07E0, 0x7D33, 0xFFFF, 0xF7DF, 0xB5F7, 0x07E0, 0xFFE1, 0xFFE0, 0xBE67, 0x07E0, 0x8D2A,   // 0x01B0 (432) pixels
0xFFE0, 0xF7C8, 0x07E0, 0xFFE1, 0xFFC0, 0xFFE0, 0xDF48, 0x07E0, 0x956A, 0xF7A2, 0xFFE0, 0xFFE0, 0xD730, 0x07E0, 0x07E0, 0x0020,   // 0x01C0 (448) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0xF7DF, 0xFFDF, 0xF7FF, 0x7470, 0x07E0, 0x07E0, 0x07E0, 0x9595,   // 0x01D0 (464) pixels
0xFFFF, 0xFFDF, 0xAE37, 0x07E0, 0xB699, 0xFFFF, 0xFFDF, 0x07E0, 0xC6BA, 0xFFFF, 0xFFFF, 0x8533, 0x07E0, 0xDF5C, 0xF7DF, 0xFFFF,   // 0x01E0 (480) pixels
0x07E0, 0x7CF2, 0xFFFF, 0xFFFF, 0xA5F6, 0x07E0, 0xCEFB, 0xFFDF, 0xF7FF, 0x07E0, 0xB66C, 0xFFE0, 0xFFC0, 0xA5A8, 0x6429, 0xEFC3,   // 0x01F0 (496) pixels
0xFFE0, 0xA5EC, 0x07E0, 0xFFE2, 0xFFE0, 0xFFE0, 0x07E0, 0x07E0, 0x07E0, 0xF7E0, 0xD6C6, 0x5C2B, 0x07E0, 0x07E0, 0x0000, 0x0020,   // 0x0200 (512) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0xEF9E, 0xFFFF, 0xF7FF, 0xCEDA, 0x07E0, 0x07E0, 0x07E0, 0xE77D,   // 0x0210 (528) pixels
0xFFDF, 0xF7DF, 0x07E0, 0x07E0, 0xEF9D, 0xFFFF, 0xF7BE, 0x07E0, 0xEF9E, 0xF7BE, 0xF7DF, 0x07E0, 0x07E0, 0xFFDF, 0xFFFF, 0xF7FF,   // 0x0220 (544) pixels
0x07E0, 0xCEFB, 0xFFDF, 0xF7FF, 0x07E0, 0x07E0, 0xF7BE, 0xFFDF, 0xDF7D, 0x07E0, 0xEF84, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,   // 0x0230 (560) pixels
0xB607, 0x07E0, 0x07E0, 0xF7E1, 0xFFE0, 0xFFE0, 0xD707, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0841, 0x0000,   // 0x0240 (576) pixels
0x0000, 0x0000, 0x0800, 0x0000, 0x0820, 0x0081, 0x07E0, 0x07E0, 0xA637, 0xFFFF, 0xFFDF, 0xF7BE, 0x9DD6, 0x07E0, 0x43CD, 0xF7FF,   // 0x0250 (592) pixels
0xFFDF, 0xEFBE, 0x07E0, 0x74B1, 0xF7FF, 0xFFDF, 0xC6BA, 0x07E0, 0xF7FF, 0xFFBF, 0xCEDA, 0x07E0, 0x8D74, 0xFFDF, 0xFFDF, 0xBEB9,   // 0x0260 (608) pixels
0x07E0, 0xFFDF, 0xFFFF, 0xE77D, 0x07E0, 0x74D2, 0xFFDF, 0xFFFF, 0xAE17, 0x07E0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0,   // 0x0270 (624) pixels
0xDF0C, 0x07E0, 0x07E0, 0xB648, 0xFFC0, 0xFFE0, 0xFFE1, 0x8D6B, 0x07E0, 0x0000, 0x0061, 0x0820, 0x0000, 0x0800, 0x0000, 0x0000,   // 0x0280 (640) pixels
0x0000, 0x0821, 0x0020, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0xDF7D, 0xFFDF, 0xFFFF, 0xEFDE, 0x07E0, 0x9594, 0xFFFF,   // 0x0290 (656) pixels
0xFFDF, 0xAE37, 0x07E0, 0xBE58, 0xF7FF, 0xFFBF, 0x07E0, 0xCEBA, 0xFFFF, 0xFFFF, 0x7D53, 0x07E0, 0xDF9D, 0xFFBF, 0xFFFF, 0x07E0,   // 0x02A0 (672) pixels
0x74B1, 0xFFDF, 0xFFDF, 0xA617, 0x07E0, 0xCEDA, 0xFFBF, 0xF7FF, 0x07E0, 0xA611, 0xFFE0, 0xFFE0, 0xB646, 0x07E0, 0xF783, 0xFFE0,   // 0x02B0 (688) pixels
0xE74F, 0x07E0, 0x07E0, 0x07E0, 0xDF06, 0xFFE0, 0xFFE0, 0xDF49, 0x07E0, 0x0881, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x02C0 (704) pixels
0x0020, 0x07E0, 0x07E0, 0x07E0, 0x6C70, 0xC69A, 0xAE58, 0x07E0, 0x07E0, 0x84F2, 0xF7DE, 0xFFFF, 0xFFFF, 0x07E0, 0xEFBE, 0xFFBF,   // 0x02D0 (720) pixels
0xF7DF, 0x07E0, 0x07E0, 0xEFBE, 0xFFDF, 0xEF9E, 0x07E0, 0xF79E, 0xFFFF, 0xFFFF, 0x07E0, 0x07E0, 0xEFDE, 0xFFDF, 0xEFBE, 0x07E0,   // 0x02E0 (736) pixels
0xC6DA, 0xFFDF, 0xFFFF, 0x640F, 0x07E0, 0xEFBE, 0xFFDF, 0xDF5D, 0x07E0, 0xEFAA, 0xFFE0, 0xFFE0, 0x07E0, 0x07E0, 0xD6E5, 0xFFE0,   // 0x02F0 (752) pixels
0x954C, 0x07E0, 0x07E0, 0x07E0, 0x8D0B, 0xFFE0, 0xFFE0, 0xEFA8, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0300 (768) pixels
0x0020, 0x07E0, 0x07E0, 0xDF5C, 0xFFDF, 0xFFDF, 0xDF1C, 0x07E0, 0x07E0, 0xE79D, 0xFFDF, 0xFFDE, 0xF7BE, 0x07E0, 0xF7FF, 0xFFFF,   // 0x0310 (784) pixels
0xFFDF, 0xB638, 0xC699, 0xF7DF, 0xFFDF, 0xA617, 0x07E0, 0xF7BF, 0xFFDF, 0xFFDF, 0x8D13, 0xDF3C, 0xFFDF, 0xFFFF, 0x8574, 0x07E0,   // 0x0320 (800) pixels
0xEF9E, 0xF7FF, 0xFFFF, 0xE77D, 0xE77D, 0xFFDF, 0xF7BE, 0x07E0, 0x07E0, 0xFFE1, 0xFFE0, 0xFFE1, 0xB608, 0xCEC5, 0xFFE0, 0xFFE2,   // 0x0330 (816) pixels
0x07E0, 0x07E0, 0x07E0, 0x07E0, 0xBE07, 0xFFE0, 0xFFE0, 0xDF49, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0340 (832) pixels
0x0020, 0x1081, 0x07E0, 0xADF7, 0xFFFF, 0xF7FF, 0xFFDF, 0xF7DF, 0xFFDF, 0xFFDF, 0xFFDF, 0xF7DF, 0x8D94, 0x07E0, 0xF7DF, 0xF7FF,   // 0x0350 (848) pixels
0xFFFF, 0xFFDF, 0xFFFF, 0xFFDF, 0xD73C, 0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0xFFDF, 0xFFFF, 0xF7BF, 0xFFDF, 0xCEFB, 0x07E0, 0x07E0,   // 0x0360 (864) pixels
0xD73C, 0xF7DF, 0xFFFF, 0xFFDF, 0xFFDF, 0xF7DF, 0xA5F6, 0x07E0, 0xBE91, 0xFFC1, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE1, 0xFFE4, 0xEF88,   // 0x0370 (880) pixels
0x07E0, 0xBE8B, 0xFFC2, 0xEFA2, 0xFFE0, 0xFFE0, 0xFFC0, 0x850B, 0x07E0, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0380 (896) pixels
0x0000, 0x0820, 0x07E0, 0x07E0, 0xE77D, 0xF7BE, 0xF7DF, 0xFFBF, 0xFFFF, 0xF7DF, 0xE73C, 0x84D2, 0x07E0, 0x07E0, 0xB678, 0xFFDF,   // 0x0390 (912) pixels
0xFFFF, 0xFFDF, 0xF7DF, 0xC6BA, 0x07E0, 0x07E0, 0x07E0, 0xDF1C, 0xFFDF, 0xFFDF, 0xFFDF, 0xF7BF, 0xB699, 0x07E0, 0x07E0, 0x07E0,   // 0x03A0 (928) pixels
0x07E0, 0xCEFB, 0xE77D, 0xE75D, 0xCEDB, 0x6CB1, 0x07E0, 0x07E0, 0xC70E, 0xFFE0, 0xE745, 0xCECB, 0xCEED, 0xBE71, 0x84F0, 0x07E0,   // 0x03B0 (944) pixels
0x07E0, 0xF7E8, 0xFFE0, 0xFFE0, 0xFFE0, 0xF7C3, 0x9DEC, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x03C0 (960) pixels
0x0000, 0x0000, 0x0820, 0x07E0, 0xFFFF, 0xFFFF, 0x3B8C, 0x84D2, 0x7CF2, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x53AD,   // 0x03D0 (976) pixels
0x8553, 0x6CD1, 0x07E0, 0x07E0, 0x07E0, 0x08A2, 0x07E0, 0x07E0, 0x6470, 0x8D74, 0x7CD2, 0x07E0, 0x07E0, 0x07E0, 0x0861, 0x0841,   // 0x03E0 (992) pixels
0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,   // 0x03F0 (1008) pixels
0x07E0, 0x07E0, 0xB66A, 0xC6CA, 0xA5EA, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0400 (1024) pixels
0x0000, 0x0000, 0x0820, 0x07E0, 0x07E0, 0xFFFF, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0,   // 0x0410 (1040) pixels
0x07E0, 0x07E0, 0x07E0, 0x0081, 0x0041, 0x0020, 0x0021, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0061, 0x0000, 0x0000, 0x0020,   // 0x0420 (1056) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0041, 0x0020, 0x0041, 0x0020, 0x0020, 0x0020, 0x0841, 0x0000, 0x0000,   // 0x0430 (1072) pixels
0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0882, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0440 (1088) pixels
0x0000, 0x0000, 0x0000, 0x0020, 0x07E0, 0x07E0, 0x07E0, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0450 (1104) pixels
0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0460 (1120) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0470 (1136) pixels
0x0800, 0x0000, 0x0020, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0480 (1152) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0881, 0x07E0, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x0490 (1168) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x04A0 (1184) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x04B0 (1200) pixels
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   // 0x04C0 (1216) pixels
};
