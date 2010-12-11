namespace eval osd {

variable default_color "0x7090aae8 0xa0c0dde8 0x90b0cce8 0xc0e0ffe8"
variable error_color "0xaa0000e8 0xdd0000e8 0xcc0000e8 0xff0000e8"
variable warning_color "0xaa6600e8 0xdd9900e8 0xcc8800e8 0xffaa00e8"

set_help_text show_osd \
{Give an overview of all currently defined OSD elements and their properties.
This is mainly useful to debug a OSD related script.}

proc show_osd {{widgets ""}} {
	set result ""
	if {$widgets == ""} {
		# all widgets
		set widgets [osd info]
	}
	foreach widget $widgets {
		append result "$widget\n"
		foreach property [osd info $widget] {
			if {[catch {set value [osd info $widget $property]}]} {
				set value "--error--"
			}
			append result "  $property $value\n"
		}
	}
	return $result
}

# this can display only one message at a time, the previous message
# will get overwritten by a new one
# TODO: chop up the line in multiple lines if it's too long
proc display_message { message {category info} } {
	variable default_color
	variable error_color
	variable warning_color
	switch -- $category {
		"info"     { set bg_color $default_color }
		"progress" { set bg_color $default_color }
		"warning"  { set bg_color $warning_color }
		"error"    { set bg_color $error_color   }
		"default"  { error "Invalid category: $category" }
	}

	osd_widgets::text_box osd_display_message \
					-text $message \
					-textrgba 0xffffffff \
					-textsize 6 \
					-rgba $bg_color \
					-x 3 -y 12 -z 5 -w 314 \
					-bordersize 0.5 \
					-borderrgba 0x000000ff \
					-clip true \
					-scaled true \
					-fadeCurrent 1 \
					-fadeTarget 0 \
					-fadePeriod 5
}


# only export stuff that is useful in other scripts or for the console user
namespace export show_osd
namespace export display_message

};# namespace osd

# only import stuff to global that is useful outside of scripts (i.e. for the console user)
namespace import osd::show_osd
