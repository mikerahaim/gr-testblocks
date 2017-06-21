#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Test file for vec_select
# Author: Michael Rahaim
# Description: Multiple delayed signal chains combined to a vector. The vec_select block picks which of the signal chains to pass along.
# Generated: Wed Jun 21 18:23:55 2017
##################################################

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from PyQt4 import Qt
from gnuradio import analog
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio import qtgui
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from gnuradio.qtgui import Range, RangeWidget
from optparse import OptionParser
import sip
import sys
import testblocks
from gnuradio import qtgui


class vec_select_test(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Test file for vec_select")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Test file for vec_select")
        qtgui.util.check_set_qss()
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
            pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "vec_select_test")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 100000
        self.my_delay = my_delay = 2

        ##################################################
        # Blocks
        ##################################################
        self._my_delay_range = Range(0, 5, 1, 2, 200)
        self._my_delay_win = RangeWidget(self._my_delay_range, self.set_my_delay, "my_delay", "counter_slider", float)
        self.top_layout.addWidget(self._my_delay_win)
        self.testblocks_vec_select_0 = testblocks.vec_select(6, my_delay+1)
        self.qtgui_time_sink_x_0 = qtgui.time_sink_f(
        	200, #size
        	samp_rate, #samp_rate
        	"", #name
        	2 #number of inputs
        )
        self.qtgui_time_sink_x_0.set_update_time(0.10)
        self.qtgui_time_sink_x_0.set_y_axis(-1, 1)

        self.qtgui_time_sink_x_0.set_y_label('Amplitude', "")

        self.qtgui_time_sink_x_0.enable_tags(-1, True)
        self.qtgui_time_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, 0, "")
        self.qtgui_time_sink_x_0.enable_autoscale(False)
        self.qtgui_time_sink_x_0.enable_grid(False)
        self.qtgui_time_sink_x_0.enable_axis_labels(True)
        self.qtgui_time_sink_x_0.enable_control_panel(False)

        if not True:
          self.qtgui_time_sink_x_0.disable_legend()

        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "blue"]
        styles = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        markers = [-1, -1, -1, -1, -1,
                   -1, -1, -1, -1, -1]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]

        for i in xrange(2):
            if len(labels[i]) == 0:
                self.qtgui_time_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_time_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_time_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_time_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_time_sink_x_0.set_line_style(i, styles[i])
            self.qtgui_time_sink_x_0.set_line_marker(i, markers[i])
            self.qtgui_time_sink_x_0.set_line_alpha(i, alphas[i])

        self._qtgui_time_sink_x_0_win = sip.wrapinstance(self.qtgui_time_sink_x_0.pyqwidget(), Qt.QWidget)
        self.top_layout.addWidget(self._qtgui_time_sink_x_0_win)
        self.blocks_throttle_0 = blocks.throttle(gr.sizeof_float*1, samp_rate,True)
        self.blocks_streams_to_vector_0 = blocks.streams_to_vector(gr.sizeof_float*1, 6)
        self.blocks_delay_0_3_0_3 = blocks.delay(gr.sizeof_float*1, 5)
        self.blocks_delay_0_3_0_2 = blocks.delay(gr.sizeof_float*1, 4)
        self.blocks_delay_0_3_0_1 = blocks.delay(gr.sizeof_float*1, 3)
        self.blocks_delay_0_3_0_0 = blocks.delay(gr.sizeof_float*1, 2)
        self.blocks_delay_0_3_0 = blocks.delay(gr.sizeof_float*1, 1)
        self.analog_sig_source_x_0 = analog.sig_source_f(samp_rate, analog.GR_SQR_WAVE, 5000, 1, -0.5)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.analog_sig_source_x_0, 0), (self.blocks_throttle_0, 0))
        self.connect((self.blocks_delay_0_3_0, 0), (self.blocks_streams_to_vector_0, 1))
        self.connect((self.blocks_delay_0_3_0_0, 0), (self.blocks_streams_to_vector_0, 2))
        self.connect((self.blocks_delay_0_3_0_1, 0), (self.blocks_streams_to_vector_0, 3))
        self.connect((self.blocks_delay_0_3_0_2, 0), (self.blocks_streams_to_vector_0, 4))
        self.connect((self.blocks_delay_0_3_0_3, 0), (self.blocks_streams_to_vector_0, 5))
        self.connect((self.blocks_streams_to_vector_0, 0), (self.testblocks_vec_select_0, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_delay_0_3_0, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_delay_0_3_0_0, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_delay_0_3_0_1, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_delay_0_3_0_2, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_delay_0_3_0_3, 0))
        self.connect((self.blocks_throttle_0, 0), (self.blocks_streams_to_vector_0, 0))
        self.connect((self.blocks_throttle_0, 0), (self.qtgui_time_sink_x_0, 0))
        self.connect((self.testblocks_vec_select_0, 0), (self.qtgui_time_sink_x_0, 1))

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "vec_select_test")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.qtgui_time_sink_x_0.set_samp_rate(self.samp_rate)
        self.blocks_throttle_0.set_sample_rate(self.samp_rate)
        self.analog_sig_source_x_0.set_sampling_freq(self.samp_rate)

    def get_my_delay(self):
        return self.my_delay

    def set_my_delay(self, my_delay):
        self.my_delay = my_delay
        self.testblocks_vec_select_0.set_select(self.my_delay+1)


def main(top_block_cls=vec_select_test, options=None):

    from distutils.version import StrictVersion
    if StrictVersion(Qt.qVersion()) >= StrictVersion("4.5.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def quitting():
        tb.stop()
        tb.wait()
    qapp.connect(qapp, Qt.SIGNAL("aboutToQuit()"), quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()
