/* ERPTier_def.h
 *
 * Copyright (C) 2011,2014,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#define ooSTRUCT ERPPoint
oo_DEFINE_CLASS (ERPPoint, AnyPoint)

	oo_AUTO_OBJECT (Sound, 2, erp)

oo_END_CLASS (ERPPoint)
#undef ooSTRUCT


#define ooSTRUCT ERPTier
oo_DEFINE_CLASS (ERPTier, AnyTier)

	#if ! oo_DECLARING
		oo_AUTO_COLLECTION (SortedSetOfDouble, points, ERPPoint, 0)
	#endif

	oo_LONG (numberOfChannels)
	oo_STRING_VECTOR (channelNames, numberOfChannels)

	#if oo_DECLARING
		ERPPoint event (long i)   // rvalue accessor
			{ return static_cast <ERPPoint> (our points -> item [i]); }

		int v_domainQuantity ()
			override { return MelderQuantity_TIME_SECONDS; }
		void v_shiftX (double xfrom, double xto)
			override;
		void v_scaleX (double xminfrom, double xmaxfrom, double xminto, double xmaxto)
			override;
	#endif

oo_END_CLASS (ERPTier)
#undef ooSTRUCT


/* End of file ERPTier_def.h */
