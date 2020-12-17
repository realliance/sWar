Creator	"yFiles"
Version	"2.17"
graph
[
	hierarchic	1
	label	""
	directed	1
	node
	[
		id	0
		label	"GameStart"
		graphics
		[
			x	96.0297619047619
			y	13.703125
			w	72.01953125
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#009EFF"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"GameStart"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	1
		label	"GameEnd"
		graphics
		[
			x	96.0297619047619
			y	415.546875
			w	68.029296875
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#BF0404"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"GameEnd"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	2
		label	"Battle"
		graphics
		[
			x	96.0297619047619
			y	71.109375
			w	44.685546875
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#009EFF"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Battle"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	3
		label	"Collect"
		graphics
		[
			x	96.0297619047619
			y	300.734375
			w	50.6796875
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#009EFF"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Collect"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	4
		label	"Declaration"
		graphics
		[
			x	96.0297619047619
			y	128.515625
			w	74.69726562499999
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#1B8C48"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Declaration"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	5
		label	"Draw"
		graphics
		[
			x	96.0297619047619
			y	358.140625
			w	42.001953125
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#009EFF"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Draw"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	6
		label	"Surrender"
		graphics
		[
			x	43.680952380952384
			y	185.921875
			w	67.361328125
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#BF0404"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Surrender"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	7
		label	"Regroup"
		graphics
		[
			x	148.37857142857143
			y	185.921875
			w	60.031249999999986
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#1B8C48"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Regroup"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	node
	[
		id	8
		label	"Duel"
		graphics
		[
			x	96.0297619047619
			y	243.328125
			w	38.6796875
			h	27.40625
			type	"ellipse"
			raisedBorder	0
			fill	"#1B8C48"
			outline	"#000000"
		]
		LabelGraphics
		[
			text	"Duel"
			color	"#FFFFFF"
			fontSize	12
			fontName	"Dialog"
			model	"null"
		]
	]
	edge
	[
		source	0
		target	2
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	2
		target	3
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	96.0297619047619
					y	71.109375
				]
				point
				[
					x	110.92494419642857
					y	99.8125
				]
				point
				[
					x	193.39444444444445
					y	99.8125
				]
				point
				[
					x	193.39444444444445
					y	300.734375
				]
				point
				[
					x	96.0297619047619
					y	300.734375
				]
			]
		]
		edgeAnchor
		[
			xSource	0.6666666666666669
			ySource	1.0
			xTarget	1.0
		]
	]
	edge
	[
		source	2
		target	4
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	3
		target	5
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	4
		target	6
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	96.0297619047619
					y	128.515625
				]
				point
				[
					x	43.680952380952384
					y	128.515625
				]
				point
				[
					x	43.680952380952384
					y	185.921875
				]
			]
		]
		edgeAnchor
		[
			xSource	-1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	4
		target	7
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	96.0297619047619
					y	128.515625
				]
				point
				[
					x	148.37857142857143
					y	128.515625
				]
				point
				[
					x	148.37857142857143
					y	185.921875
				]
			]
		]
		edgeAnchor
		[
			xSource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	5
		target	1
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	5
		target	2
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	96.0297619047619
					y	358.140625
				]
				point
				[
					x	208.39444444444445
					y	358.140625
				]
				point
				[
					x	208.39444444444445
					y	71.109375
				]
				point
				[
					x	96.0297619047619
					y	71.109375
				]
			]
		]
		edgeAnchor
		[
			xSource	1.0
			xTarget	1.0
		]
	]
	edge
	[
		source	6
		target	1
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	43.680952380952384
					y	185.921875
				]
				point
				[
					x	43.680952380952384
					y	415.546875
				]
				point
				[
					x	96.0297619047619
					y	415.546875
				]
			]
		]
		edgeAnchor
		[
			ySource	1.0
			xTarget	-1.0
		]
	]
	edge
	[
		source	7
		target	8
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
			Line
			[
				point
				[
					x	148.37857142857143
					y	185.921875
				]
				point
				[
					x	148.37857142857143
					y	243.328125
				]
				point
				[
					x	96.0297619047619
					y	243.328125
				]
			]
		]
		edgeAnchor
		[
			ySource	1.0
			xTarget	1.0
		]
	]
	edge
	[
		source	8
		target	3
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	1.0
			yTarget	-1.0
		]
	]
	edge
	[
		source	8
		target	4
		graphics
		[
			fill	"#000000"
			targetArrow	"standard"
		]
		edgeAnchor
		[
			ySource	-1.0
			yTarget	1.0
		]
	]
]
