//
//  RandomChunk.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/8/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

// Apple 2nd PS, chunkReader

class MessageSender {
public:
    send(uint8_t messageData, uint32_t messageSize);
}

class ChunkReader {
    uint8_t* m_buffer;
    uint32_t m_bufferSize;
    uint32_t m_readBuffer;
    uint32_t m_writtenBuffer;
    
    uint32_t m_messageSize;
    
    uint32_t s_headerSize;
    
    MessageSender* m_sender;
    
    
    
    
public:
    ChunkReader() {
        m_buffer = new uint8_t[0];
        m_bufferSize =0;
        m_readBuffer =0;
        m_writtenBuffer =0;
        m_messageSize = 0;
        
        s_headerSize = 4;
        
        m_sender = new MessageSender();
        
        
    }
    
    void accept(uint8_t* chunkData, uint32_t chunkSize) {
        uint32_t readChunk = 0;
        while (chunkSize > readChunk) {
            uint32_t needBuffer = (m_messageSize == 0? m_headerSize: m_messageSize);
            if (needBuffer > m_bufferSize - m_writtenBuffer) {
                compactBuffer(needBuffer);
            }
            
            uint32_t remaining = min(chunkSize - readChunk, needBuffer - m_writtenBuffer);
            
            memcpy(m_buffer + m_writtenBuffer,
                   chunkData + readChunk, remaining);
            
            readChunk += remaining;
            m_writtenBuffer += remaining;
            
            if (m_messageSize == 0 && m_writtenBuffer - m_readBuffer >= s_headerSize) {
                m_messageSize = (uint32_t)*(m_buffer+m_readBuffer);
                m_readBuffer += s_headerSize;
            }
            
            if (m_messageSize >0 && m_writtenBuffer - m_readBuffer >= m_messageSize) {
                m_sender.send(m_buffer + m_readBuffer, m_messageSize);
                m_readBuffer += m_messageSize;
                m_messageSize = 0;
            }
        }
    }
    
    void compactBuffer(size32_t newBufferSize) {
        uint8_t* newBuffer = new uint8_t[newBufferSize];
        memcpy(newBuffer, m_buffer+m_readBuffer, m_writtenBuffer - m_readBuffer);
        delete m_buffer;
        m_buffer = newBuffer;
        m_bufferSize = newBufferSize;
        m_writtenBuffer -= m_readBuffer;
        m_readBuffer = 0;
    }
    
};
