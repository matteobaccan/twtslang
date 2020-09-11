/*
 * TWT Slang 1.10
 *
 * Copyright 2000 Matteo Baccan <mbaccan@planetisa.com>
 * www - http://www.infomedia.it/artic/Baccan
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA (or visit
 * their web site at http://www.gnu.org/).
 *
 */

/*
  ÉÍÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÍ»
  ³ş  ____       __                                                       ş³
  ³  /    \____ /  \                                                       ³
  ³  \____/  __/    \       ________    ________             TWT           ³
  ³    |\ | |  | /\ |       \__  __ \/\/ __  __/                           ³
  ³    | ||  ==| \/ |          \ \ \    / / /               Slang          ³
  ³    | || |  \    /  of       \ \ \/\/ / /                               ³
  ³    | || \__ \__/             \/      \/               Converter        ³
  ³     \| \___\             The WoNdERfuL TeaM                            ³
  ³ş                                                                      ş³
  ÈÍÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÍ¼
  v1.02 Added some chars by úÄÍşIANşÍÄú
  v1.03 Some little changes úÄÍşTEOşÍÄú
  v1.10 Source released
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <io.h>

#define BUFFER_LEN   4096 // buffer lenght
#define CV_EXITPARA     1 // parameter error
#define CV_EXITOPEN     2 // open error
#define CV_EXITEXIST    3 // file exist

void dfPrintLogo(void);      // logo
void dfPrintInfo(void);      // parameter info
void dfPrintOpenError( const char * InFile ); // open error
void dfPrintExist( const char * OutFile );    // file Exist
void dfConvert( char * Buffer, int Count );  // convert string

void main(int argc, char *argv[])
{
   FILE *InFile, *OutFile;     // file declaration
   char *RBuffer;              // Read Buffer
   int  CharRead;              // Char read

   if( argc < 3 ){                                 // check parameter
      dfPrintInfo();
      exit( CV_EXITPARA );
   }// endif

   dfPrintLogo();

   if( access( argv[2], 00 ) >= 0 ){               // file exist
      dfPrintExist( argv[2] );
      exit( CV_EXITEXIST );
   }// endif

   if( (InFile = fopen( argv[1], "r")) == NULL ){  // open file
      dfPrintOpenError( argv[1] );
      exit( CV_EXITOPEN );
   }// endif

   if( (OutFile = fopen( argv[2], "w")) == NULL ){ // create file
      dfPrintOpenError( argv[2] );
      exit( CV_EXITOPEN );
   }// endif

   printf("\n ş Reading %s\n", argv[1] );          // Convert
   RBuffer = malloc( BUFFER_LEN );
   while( (CharRead = fread(RBuffer, sizeof(char), BUFFER_LEN, InFile )) >0 ){
      dfConvert( RBuffer, CharRead );
      fwrite( RBuffer, sizeof(char), CharRead, OutFile );
   }// endwhile
   free( RBuffer );
   printf("\n ş OK \n" );

   fclose( InFile );                               // Close File
   fclose( OutFile );

}// end of main


void dfPrintInfo(){
   printf("\nTWTSlang        Converter file ASCII in TWT Slang       Version  1.10 \n");
   printf("Copyright 1993-1996 The Wonderful Team.    All Rights Reserved.         \n");
   printf("                                                                        \n");
   printf("Usage: TWTSlang <InFile> <OutFile>                                      \n");
   printf("                                                                        \n");
   printf(" InFile  = File 2 convert into TWT slang                                \n");
   printf("                                                                        \n");
   printf(" OutFile = File 2 save                                                  \n");
   printf("                                                                        \n");
   printf("                     şÄÄÍÍ çîå ç×î SåŸçWizàâd ÍÍÄÄş                     \n");
}// end of print info

void dfPrintLogo(){
   printf("\n");
   printf("ÉÍÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÍ»\n");
   printf("³ş                                                                      ş³\n");
   printf("³  The Wonderful Team                                   Slang Converter  ³\n");
   printf("³ş                                 1.10                                 ş³\n");
   printf("ÈÍÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÍ¼\n");
   printf("                     şÄÄÍÍ çîå ç×î SåŸçWizàâd ÍÍÄÄş                       \n");
}// end of print logo


void dfPrintOpenError( const char * InFile ){
   printf("\n ş Error opening file %s\n", InFile );
}// end of print error


void dfPrintExist( const char * OutFile ){
   printf("\n ş Output file %s Exist \n", OutFile );
}// end of print Exist


void dfConvert( char * Buffer, int Count ){
   char c2Put;  // char to put

   while( Count-- > 0 ){
      switch( Buffer[Count] ){
      case 'a' :
         c2Put = 'à';
         break;
      case 'A' :
         c2Put = '’';
         break;
      case 'b' :
      case 'B' :
         c2Put = 'á';
         break;
      case 'c' :
         c2Put = '‡';
         break;
      case 'C' :
         c2Put = '<';
         break;
      case 'd' :
         c2Put = 'ë';
         break;
      case 'e' :
         c2Put = 'î';
         break;
      case 'E' :
         c2Put = 'ä';
         break;
      case 'f' :
         c2Put = 'Ÿ';
         break;
      case 'F' :
         c2Put = 'Õ';
         break;
      case 'h' :
      case 'H' :
         c2Put = '×';
         break;
      case 'i' :
         c2Put = '­';
         break;
      case 'I' :
         c2Put = '³';
         break;
      case 'j' :
      case 'J' :
         c2Put = 'õ';
         break;
      case 'l' :
         c2Put = '';
         break;
      case 'L' :
         c2Put = 'œ';
         break;
      case 'n' :
         c2Put = 'ã';
         break;
      case 'N' :
         c2Put = 'ï';
         break;
      case 'o' :
         c2Put = 'å';
         break;
      case 'O' :
         c2Put = 'é';
         break;
      case 'p' :
      case 'P' :
         c2Put = 'ô';
         break;
      case 'q' :
         c2Put = '';
         break;
      case 'r' :
         c2Put = 'â';
         break;
      case 'R' :
         c2Put = '';
         break;
      case 'S' :
         c2Put = '$';
         break;
      case 't' :
      case 'T' :
         c2Put = 'ç';
         break;
      case 'v' :
      case 'V' :
         c2Put = 'û';
         break;
      case 'Y' :
         c2Put = '';
         break;
      case 'x' :
         c2Put = '%';
         break;
      default:
         c2Put = Buffer[Count];
      }// endSwitch
      Buffer[Count] = c2Put;
   }// endwhile
}// end of convert
